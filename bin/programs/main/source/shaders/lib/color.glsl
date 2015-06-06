#ifndef COLOR_INCLUDED
#define COLOR_INCLUDED

vec3 toSRGB(vec3 color)
{
    vec3 S1 = sqrt(color);
    vec3 S2 = sqrt(S1);
    vec3 S3 = sqrt(S2);

    return 0.662002687 * S1 +
           0.684122060 * S2 -
           0.323583601 * S3 -
           .0225411470 * color;
}

vec4 toSRGB(vec4 color)
{
    return vec4(toSRGB(color.rgb), color.a);
}

vec3 toLinear(vec3 color)
{
    return pow(color, vec3(2.2));
}

vec4 toLinear(vec4 color)
{
    return vec4(toLinear(color.rgb), color.a);
}

#endif

