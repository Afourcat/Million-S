#version 130

uniform sampler2D texture;

void main()
{
    vec4 color = vec4(gl_FragCoord.y / 1080,
     gl_FragCoord.y / 1080, gl_FragCoord.x / 1920, 1.);
    gl_FragColor = color;
}