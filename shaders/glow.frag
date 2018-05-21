#version 130
uniform sampler2D current;
uniform sampler2D texture;
uniform float time_t;

void main()
{
    vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);
    gl_FragColor = vec4(
	sin(time_t),
	cos(time_t),
	sin(time_t) * cos(time_t),
	1.0);
}
