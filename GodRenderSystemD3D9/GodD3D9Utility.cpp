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
}