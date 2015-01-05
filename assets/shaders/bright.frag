
uniform sampler2D source;
const float brightPassThreshold = 0.7;
varying vec2 vTexCoord;

void main(void) {
    vec3 luminanceVector = vec3(0.2125, 0.7154, 0.0721);
    vec4 sample = texture2D(source, vTexCoord.st);

    float luminance = dot(luminanceVector, sample.rgb);
    luminance = max(0.0, luminance - brightPassThreshold);
    sample.rgb *= sign(luminance);
    sample.a = 1.0;

    gl_FragColor = sample;
}