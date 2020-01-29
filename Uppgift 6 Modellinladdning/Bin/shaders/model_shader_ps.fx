#include "common.fx"

SamplerState SampleType;
Texture2D shaderTexture : register( t4 );

float4 PShader(PixelInputType input) : SV_TARGET
{
	float4 Diffuse = shaderTexture.Sample(SampleType, input.tex);
	if(Diffuse.a <= 0.0)
	{
		discard;
	}
	Diffuse.a = 1;
	return Diffuse;
}