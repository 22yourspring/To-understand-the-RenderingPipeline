struct VertexInput
{
	float4 Position : POSITION0;
	float2 UV : TEXCOORD0;
};

struct PixelInput
{
	float4 Position : SV_POSITION0;
	float2 UV : TEXCOORD0;
};

cbuffer Transform : register(b0) // Slot : 0 ~ 13		4096 * 16Byte
{
	matrix World;
	matrix View;
	matrix Projection;
};

Texture2D SourceTexture1 : register(t0);
Texture2D SourceTexture2 : register(t1);
SamplerState Sampler	: register(s0);

PixelInput VS(VertexInput _Input)
{
	PixelInput Output;
	
	Output.Position = mul(_Input.Position, World);
	Output.Position = mul(Output.Position, View);
	Output.Position = mul(Output.Position, Projection);
	Output.UV = _Input.UV;
	
	return Output;
}

float4 PS(PixelInput _Input) : SV_Target
{
	float4 Color = SourceTexture1.Sample(Sampler, _Input.UV);
	
	return Color;
}