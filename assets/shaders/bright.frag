uniform sampler2D source;

const float Threshold = 0.7;
const float Factor   = 4.0;
varying vec2 vTexCoord;
void main()
{
	vec4 sourceFragment = texture2D(source, vTexCoord.xy);
	float luminance = sourceFragment.r * 0.2126 + sourceFragment.g * 0.7152 + sourceFragment.b * 0.0722;
	sourceFragment *= clamp(luminance - Threshold, 0.0, 1.0) * Factor;
	gl_FragColor = sourceFragment;
}