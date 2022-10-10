struct VertexInput
{
	float4 Position : POSITION0;
	float4 Color	: COLOR0;
};

struct PixelInput
{
	float4 Position : SV_POSITION0;
	float4 Color	: COLOR0;
};

cbuffer Transform : register(b0) // Slot : 0 ~ 13		4096 * 16Byte
{
	matrix World;
	matrix View;
	matrix Projection;
};

PixelInput VertexShader(VertexInput _Input)
{
	PixelInput Output;
	
	Output.Position = mul(_Input.Position, World);
	Output.Position = mul(Output.Position, View);
	Output.Position = mul(Output.Position, Projection);
	Output.Color = _Input.Color;
	
	return Output;
}

float4 PixelShader(PixelInput _Input) : SV_Target
{
	return _Input.Color;
}