uniform sampler2D source1;
uniform sampler2D source2;
varying vec2 vTexCoord;

void main()
{
    gl_FragColor = texture2D(source1, vTexCoord.xy) + texture2D(source2, vTexCoord.xy);
}