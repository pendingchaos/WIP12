#ifndef PARALLAX_INCLUDED
#define PARALLAX_INCLUDED

vec2 parallaxMapping(sampler2D heightTex, vec2 original, vec3 viewDir_tangentSpace, float heightScale)
{
    //For some reason, the y needs to be inverted.
    viewDir_tangentSpace.y *= -1.0;

    float height = 1.0 - texture(heightTex, original).r;
    
    return original - viewDir_tangentSpace.xy / viewDir_tangentSpace.z * (height * heightScale);
}

vec2 pom(sampler2D heightTex,
         vec2 original,
         vec3 viewDir_tangentSpace,
         float heightScale,
         uint minLayers,
         uint maxLayers)
{
    viewDir_tangentSpace.y *= -1.0;

    float numLayers = mix(minLayers, maxLayers, abs(dot(vec3(0.0, 0.0, 1.0), viewDir_tangentSpace)));
    float layerDepth = 1.0 / numLayers;
    float currentLayerDepth = 0.0;
    vec2 P = viewDir_tangentSpace.xy / viewDir_tangentSpace.z * heightScale;
    vec2 deltaTexCoords = P / numLayers;
    
    vec2 coord = original;
    float currentDepthValue = 1.0 - textureLod(heightTex, original, 0).r;
    
    while (currentLayerDepth < currentDepthValue)
    {
        coord -= deltaTexCoords;
        
        currentDepthValue = 1.0 - textureLod(heightTex, coord, 0).r;
        
        currentLayerDepth += layerDepth;
    }
    
    vec2 previous = coord + deltaTexCoords;
    
    float afterDepth = currentDepthValue - currentLayerDepth;
    float beforeDepth = 1.0 - texture(heightTex, previous).r - currentLayerDepth + layerDepth;
    
    return mix(coord, previous, afterDepth / (afterDepth - beforeDepth));
}

#endif

