#include "GodD3D9Utility.h"

namespace GodEngine
{
	D3DMULTISAMPLE_TYPE D3D9Utility::intToD3DSAMPLETYPE(int numSamp)
	{
		D3DMULTISAMPLE_TYPE type = D3DMULTISAMPLE_NONE;
		switch (numSamp)
		{
		case 0:
			type = D3DMULTISAMPLE_NONE;
			break;
		case 1:
			type = D3DMULTISAMPLE_NONMASKABLE;
			break;
		case 2:
			type = D3DMULTISAMPLE_2_SAMPLES;
			break;
		case 3:
			type = D3DMULTISAMPLE_3_SAMPLES;
			break;
		case 4:
			type = D3DMULTISAMPLE_4_SAMPLES;
			break;
		case 5:
			type = D3DMULTISAMPLE_5_SAMPLES;
			break;
		case 6:
			type = D3DMULTISAMPLE_6_SAMPLES;
			break;
		case 7:
			type = D3DMULTISAMPLE_7_SAMPLES;
			break;
		case 8:
			type = D3DMULTISAMPLE_8_SAMPLES;
			break;
// 		case 9:
// 			type = D3DMULTISAMPLE_9_SAMPLES;
// 			break;
// 		case 10:
// 			type = D3DMULTISAMPLE_10_SAMPLES;
// 			break;
// 		case 11:
// 			type = D3DMULTISAMPLE_11_SAMPLES;
// 			break;
// 		case 12:
// 			type = D3DMULTISAMPLE_12_SAMPLES;
// 			break;
// 		case 13:
// 			type = D3DMULTISAMPLE_13_SAMPLES;
// 			break;
// 		case 14:
// 			type = D3DMULTISAMPLE_14_SAMPLES;
// 			break;
// 		case 15:
// 			type = D3DMULTISAMPLE_15_SAMPLES;
// 			break;
// 		case 16:
// 			type = D3DMULTISAMPLE_16_SAMPLES;
// 			break;
		}
		return type;
	}

	D3DDECLMETHOD D3D9Utility::GodVertMethodToD3DDECLMETHOD(const GOD_VERTEX_METHOD vertMethod)
	{
		D3DDECLMETHOD meth = D3DDECLMETHOD_DEFAULT;

		switch (vertMethod)
		{
		case GVM_DEFAULT:
			meth = D3DDECLMETHOD_DEFAULT;
			break;
		case GVM_PARTIALU:
			meth = D3DDECLMETHOD_PARTIALU;
			break;
		case GVM_PARTIALV:
			meth = D3DDECLMETHOD_PARTIALV;
			break;
		case GVM_CROSSUV:
			meth = D3DDECLMETHOD_CROSSUV;
			break;
		case GVM_UV:
			meth = D3DDECLMETHOD_UV;
			break;
		case GVM_LOOKUP:
			meth = D3DDECLMETHOD_LOOKUP;
			break;
		case GVM_LOOKUPPRESAMPLED:
			meth = D3DDECLMETHOD_LOOKUPPRESAMPLED;
			break;
		}
		return meth;
	}
	D3DDECLTYPE D3D9Utility::GodVertTypeToD3DDECLTYPE(const GOD_VERTEX_DATA_TYPE vertType)
	{
		D3DDECLTYPE declType = D3DDECLTYPE_UNUSED;
		switch (vertType)
		{
		case GVDT_FLOAT1:
			declType = D3DDECLTYPE_FLOAT1;
			break;
		case GVDT_FLOAT2:
			declType = D3DDECLTYPE_FLOAT2;
			break;
		case GVDT_FLOAT3:
			declType = D3DDECLTYPE_FLOAT3;
			break;
		case  GVDT_FLOAT4:
			declType = D3DDECLTYPE_FLOAT4;
			break;
		case GVDT_D3DCOLOR:
			declType = D3DDECLTYPE_D3DCOLOR;
			break;
		case GVDT_UBYTE4:
			declType = D3DDECLTYPE_UBYTE4;
			break;
		case GVDT_SHORT2:
			declType = D3DDECLTYPE_SHORT2;
			break;
		case GVDT_SHORT4:
			declType = D3DDECLTYPE_SHORT4;
			break;
		case GVDT_UBYTE4N:
			declType = D3DDECLTYPE_UBYTE4N;
			break;
		case GVDT_SHORT2N:
			declType = D3DDECLTYPE_SHORT2N;
			break;
		case GVDT_SHORT4N:
			declType = D3DDECLTYPE_SHORT4N;
			break;
		case GVDT_USHORT2N:
			declType = D3DDECLTYPE_USHORT2N;
			break;
		case GVDT_USHORT4N:
			declType = D3DDECLTYPE_USHORT4N;
			break;
		case GVDT_UDEC3:
			declType = D3DDECLTYPE_UDEC3;
			break;
		case GVDT_DEC3N:
			declType = D3DDECLTYPE_DEC3N;
			break;
		case GVDT_FLOAT16_2:
			declType = D3DDECLTYPE_FLOAT16_2;
			break;
		case GVDT_FLOAT16_4:
			declType = D3DDECLTYPE_FLOAT16_4;
			break;
		case GVDT_UNUSED:
			declType = D3DDECLTYPE_UNUSED;
			break;
		}
		return declType;
	}
	D3DDECLUSAGE D3D9Utility::GodVertUsageToD3DDECLUSAGE(const GOD_VERTEX_USAGE_TYPE vertUsage)
	{
		D3DDECLUSAGE declUsage = D3DDECLUSAGE_POSITION;

		switch (vertUsage)
		{
		case GVUT_POSITION: 
			declUsage = D3DDECLUSAGE_POSITION;
			break;
		case GVUT_BLENDWEIGHT: 
			declUsage = D3DDECLUSAGE_BLENDWEIGHT;
			break;
		case GVUT_BLENDINDICES:
			declUsage = D3DDECLUSAGE_BLENDINDICES;
			break;
		case GVUT_NORMAL:
			declUsage = D3DDECLUSAGE_NORMAL;
			break;
		case GVUT_PSIZE:
			declUsage = D3DDECLUSAGE_PSIZE;
			break;
		case GVUT_TEXCOORD:
			declUsage = D3DDECLUSAGE_TEXCOORD;
			break;
		case GVUT_TANGENT:
			declUsage = D3DDECLUSAGE_TANGENT;
			break;
		case GVUT_BINORMAL:
			declUsage = D3DDECLUSAGE_BINORMAL;
			break;
		case GVUT_TESSFACTOR:
			declUsage = D3DDECLUSAGE_TESSFACTOR;
			break;
		case GVUT_POSITIONT:
			declUsage = D3DDECLUSAGE_POSITIONT;
			break;
		case GVUT_COLOR:
			declUsage = D3DDECLUSAGE_COLOR; 
			break;
		case GVUT_FOG:	
			declUsage = D3DDECLUSAGE_FOG;
		case GVUT_DEPTH:
			declUsage = D3DDECLUSAGE_DEPTH;
			break;
		case GVUT_SAMPLE:
			declUsage = D3DDECLUSAGE_SAMPLE;
			break;
		}
		return declUsage;
	}

	D3DFORMAT D3D9Utility::StringToD3DFORMAT(const String fmt)
	{
		D3DFORMAT frmt = D3DFMT_UNKNOWN;

		if (fmt == "A8R8G8B8")
		{
			frmt = D3DFMT_A8R8G8B8;
		}
		else if (fmt == "X8R8G8B8")
		{
			frmt = D3DFMT_X8R8G8B8;
		}
		return frmt;
	}
}