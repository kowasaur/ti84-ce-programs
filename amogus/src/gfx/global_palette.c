unsigned char global_palette[512] =
{
    0x10, 0x7c, /*   0: rgb(255,   0, 132) */
    0xff, 0xff, /*   1: rgb(255, 255, 255) */
    0xbf, 0x6b, /*   2: rgb(214, 235, 255) */
    0xdf, 0x6f, /*   3: rgb(222, 243, 255) */
    0xbe, 0xeb, /*   4: rgb(214, 239, 247) */
    0xbe, 0xef, /*   5: rgb(222, 239, 247) */
    0xbf, 0x6f, /*   6: rgb(222, 235, 255) */
    0xbe, 0x6b, /*   7: rgb(214, 235, 247) */
    0xbf, 0xef, /*   8: rgb(222, 239, 255) */
    0xbe, 0x6f, /*   9: rgb(222, 235, 247) */
    0x9d, 0xeb, /*  10: rgb(214, 231, 239) */
    0x0f, 0x7c, /*  11: rgb(255,   0, 123) */
    0x9e, 0xef, /*  12: rgb(222, 231, 247) */
    0x9d, 0x6b, /*  13: rgb(214, 227, 239) */
    0x8d, 0xad, /*  14: rgb( 90, 101, 107) */
    0x00, 0x00, /*  15: rgb(  0,   0,   0) */
    0x86, 0x9c, /*  16: rgb( 58,  36,  49) */
    0xdf, 0x6b, /*  17: rgb(214, 243, 255) */
    0x64, 0x8c, /*  18: rgb( 25,  28,  33) */
    0x64, 0x90, /*  19: rgb( 33,  28,  33) */
    0xf8, 0x56, /*  20: rgb(173, 186, 197) */
    0x7c, 0x67, /*  21: rgb(206, 219, 230) */
    0x9d, 0xef, /*  22: rgb(222, 231, 239) */
    0x2f, 0xf8, /*  23: rgb(247,  12, 123) */
    0x3a, 0xdf, /*  24: rgb(189, 206, 214) */
    0x7d, 0xe7, /*  25: rgb(206, 223, 239) */
    0x8d, 0x25, /*  26: rgb( 74,  97, 107) */
    0x85, 0x90, /*  27: rgb( 33,  36,  41) */
    0x0f, 0xf8, /*  28: rgb(247,   4, 123) */
    0x33, 0xc2, /*  29: rgb(132, 142, 156) */
    0x4b, 0xa1, /*  30: rgb( 66,  85,  90) */
    0x19, 0x5b, /*  31: rgb(181, 194, 206) */
    0x96, 0xce, /*  32: rgb(156, 166, 181) */
    0x64, 0x14, /*  33: rgb( 41,  24,  33) */
    0xa6, 0x10, /*  34: rgb( 33,  40,  49) */
    0x4b, 0xa5, /*  35: rgb( 74,  85,  90) */
    0xae, 0xb1, /*  36: rgb( 99, 109, 115) */
    0x65, 0x98, /*  37: rgb( 49,  28,  41) */
    0x46, 0xa8, /*  38: rgb( 82,  20,  49) */
    0x5b, 0xe3, /*  39: rgb(197, 215, 222) */
    0x44, 0x98, /*  40: rgb( 49,  20,  33) */
    0x30, 0x7c, /*  41: rgb(255,   8, 132) */
    0x3b, 0xe3, /*  42: rgb(197, 206, 222) */
    0x8d, 0x29, /*  43: rgb( 82,  97, 107) */
    0x4a, 0xd0, /*  44: rgb(165,  20,  82) */
    0x1a, 0xcf, /*  45: rgb(156, 198, 214) */
    0x5b, 0x63, /*  46: rgb(197, 210, 222) */
    0xe7, 0x1c, /*  47: rgb( 58,  57,  58) */
    0x66, 0xb0, /*  48: rgb( 99,  28,  49) */
    0x7c, 0x6b, /*  49: rgb(214, 219, 230) */
    0x10, 0x3a, /*  50: rgb(115, 130, 132) */
    0x64, 0x20, /*  51: rgb( 66,  24,  33) */
    0xc7, 0x1c, /*  52: rgb( 58,  49,  58) */
    0x2f, 0xf4, /*  53: rgb(239,  12, 123) */
    0x85, 0x1c, /*  54: rgb( 58,  32,  41) */
    0x8c, 0xe0, /*  55: rgb(197,  36,  99) */
    0x64, 0x1c, /*  56: rgb( 58,  24,  33) */
    0xf0, 0x35, /*  57: rgb(107, 121, 132) */
    0x7c, 0xeb, /*  58: rgb(214, 223, 230) */
    0x6c, 0x29, /*  59: rgb( 82,  89,  99) */
    0x3a, 0x5f, /*  60: rgb(189, 202, 214) */
    0x65, 0x24, /*  61: rgb( 74,  24,  41) */
    0x75, 0xca, /*  62: rgb(148, 158, 173) */
    0x4e, 0xf0, /*  63: rgb(230,  20, 115) */
    0xb6, 0x4e, /*  64: rgb(156, 170, 181) */
    0x4f, 0xf8, /*  65: rgb(247,  20, 123) */
    0x64, 0x0c, /*  66: rgb( 25,  24,  33) */
    0x8d, 0x68, /*  67: rgb(214,  32, 107) */
    0xe8, 0x9c, /*  68: rgb( 58,  61,  66) */
    0x53, 0x46, /*  69: rgb(140, 146, 156) */
    0x7c, 0xe7, /*  70: rgb(206, 223, 230) */
    0x2a, 0xa1, /*  71: rgb( 66,  77,  82) */
    0xc7, 0x94, /*  72: rgb( 41,  53,  58) */
    0xc7, 0x14, /*  73: rgb( 41,  49,  58) */
    0x74, 0xca, /*  74: rgb(148, 158, 165) */
    0xcd, 0xdc, /*  75: rgb(189,  53, 107) */
    0x44, 0x08, /*  76: rgb( 16,  16,  33) */
    0x85, 0x8c, /*  77: rgb( 25,  36,  41) */
    0x8d, 0x2d, /*  78: rgb( 90,  97, 107) */
    0xf9, 0x4a, /*  79: rgb(148, 186, 206) */
    0xc6, 0x14, /*  80: rgb( 41,  49,  49) */
    0x4d, 0xe8, /*  81: rgb(214,  20, 107) */
    0x09, 0x9d, /*  82: rgb( 58,  69,  74) */
    0x8e, 0x68, /*  83: rgb(214,  32, 115) */
    0x19, 0xdf, /*  84: rgb(189, 198, 206) */
    0x3b, 0xd7, /*  85: rgb(173, 206, 222) */
    0x7c, 0x63, /*  86: rgb(197, 219, 230) */
    0x89, 0xc0, /*  87: rgb(132,  36,  74) */
    0xb7, 0xd2, /*  88: rgb(165, 174, 189) */
    0xbe, 0x67, /*  89: rgb(206, 235, 247) */
    0xbe, 0xf3, /*  90: rgb(230, 239, 247) */
    0x47, 0x34, /*  91: rgb(107,  16,  58) */
    0xb6, 0xd2, /*  92: rgb(165, 174, 181) */
    0xb5, 0x4a, /*  93: rgb(148, 170, 173) */
    0xf8, 0x5a, /*  94: rgb(181, 186, 197) */
    0xf8, 0xda, /*  95: rgb(181, 190, 197) */
    0x74, 0xc6, /*  96: rgb(140, 158, 165) */
    0xff, 0x7b, /*  97: rgb(247, 251, 255) */
    0x29, 0x21, /*  98: rgb( 66,  73,  74) */
    0xf1, 0xbd, /*  99: rgb(123, 125, 140) */
    0xd7, 0x52, /* 100: rgb(165, 178, 189) */
    0x95, 0x4a, /* 101: rgb(148, 162, 173) */
    0x6f, 0xf4, /* 102: rgb(239,  28, 123) */
    0x5b, 0x67, /* 103: rgb(206, 210, 222) */
    0x12, 0xbe, /* 104: rgb(123, 134, 148) */
    0x6c, 0x25, /* 105: rgb( 74,  89,  99) */
    0x00, 0x80, /* 106: rgb(  0,   4,   0) */
    0xae, 0x6c, /* 107: rgb(222,  40, 115) */
    0xe8, 0x94, /* 108: rgb( 41,  61,  66) */
    0x2e, 0xec, /* 109: rgb(222,  12, 115) */
    0x22, 0x84, /* 110: rgb(  8,  12,  16) */
    0x6c, 0xad, /* 111: rgb( 90,  93,  99) */
    0xaa, 0xc8, /* 112: rgb(148,  45,  82) */
    0xd7, 0xd6, /* 113: rgb(173, 182, 189) */
    0x49, 0xc8, /* 114: rgb(148,  20,  74) */
    0xa6, 0x94, /* 115: rgb( 41,  45,  49) */
    0xae, 0x70, /* 116: rgb(230,  40, 115) */
    0x43, 0x8c, /* 117: rgb( 25,  20,  25) */
    0x90, 0xf8, /* 118: rgb(247,  36, 132) */
    0x9d, 0xe7, /* 119: rgb(206, 231, 239) */
    0x68, 0x40, /* 120: rgb(132,  24,  66) */
    0x4a, 0xa1, /* 121: rgb( 66,  85,  82) */
    0x9d, 0x67, /* 122: rgb(206, 227, 239) */
    0x2a, 0x21, /* 123: rgb( 66,  73,  82) */
    0xbe, 0xe7, /* 124: rgb(206, 239, 247) */
    0x43, 0x88, /* 125: rgb( 16,  20,  25) */
    0x85, 0x14, /* 126: rgb( 41,  32,  41) */
    0x6c, 0xdc, /* 127: rgb(189,  28,  99) */
    0x4b, 0xa9, /* 128: rgb( 82,  85,  90) */
    0xeb, 0xc4, /* 129: rgb(140,  61,  90) */
    0x75, 0xbe, /* 130: rgb(123, 158, 173) */
    0x3a, 0x5b, /* 131: rgb(181, 202, 214) */
    0x2e, 0x70, /* 132: rgb(230,   8, 115) */
    0xf0, 0x39, /* 133: rgb(115, 121, 132) */
    0xcf, 0x31, /* 134: rgb( 99, 113, 123) */
    0x3a, 0x53, /* 135: rgb(165, 202, 214) */
    0x3a, 0x63, /* 136: rgb(197, 202, 214) */
    0x73, 0x46, /* 137: rgb(140, 154, 156) */
    0x86, 0xa0, /* 138: rgb( 66,  36,  49) */
    0x2f, 0xfc, /* 139: rgb(255,  12, 123) */
    0x7d, 0xeb, /* 140: rgb(214, 223, 239) */
    0x19, 0xdb, /* 141: rgb(181, 198, 206) */
    0x08, 0x19, /* 142: rgb( 49,  65,  66) */
    0xde, 0x6b, /* 143: rgb(214, 243, 247) */
    0xa5, 0x10, /* 144: rgb( 33,  40,  41) */
    0xa8, 0xb0, /* 145: rgb( 99,  45,  66) */
    0x54, 0xc6, /* 146: rgb(140, 150, 165) */
    0x32, 0x3e, /* 147: rgb(123, 138, 148) */
    0xf8, 0xd6, /* 148: rgb(173, 190, 197) */
    0x2e, 0x6c, /* 149: rgb(222,   8, 115) */
    0xcf, 0xb5, /* 150: rgb(107, 117, 123) */
    0x65, 0x8c, /* 151: rgb( 25,  28,  41) */
    0x1a, 0xdf, /* 152: rgb(189, 198, 214) */
    0xdf, 0x73, /* 153: rgb(230, 243, 255) */
    0x09, 0x19, /* 154: rgb( 49,  65,  74) */
    0x43, 0x14, /* 155: rgb( 41,  16,  25) */
    0x5b, 0x5f, /* 156: rgb(189, 210, 222) */
    0x11, 0xbe, /* 157: rgb(123, 134, 140) */
    0xce, 0x35, /* 158: rgb(107, 113, 115) */
    0x73, 0x4a, /* 159: rgb(148, 154, 156) */
    0xa6, 0x98, /* 160: rgb( 49,  45,  49) */
    0x88, 0xb4, /* 161: rgb(107,  36,  66) */
    0x95, 0xce, /* 162: rgb(156, 166, 173) */
    0x86, 0x24, /* 163: rgb( 74,  32,  49) */
    0x86, 0x18, /* 164: rgb( 49,  32,  49) */
    0x4a, 0xa5, /* 165: rgb( 74,  85,  82) */
    0x4a, 0x4c, /* 166: rgb(156,  16,  82) */
    0x2d, 0x68, /* 167: rgb(214,   8, 107) */
    0x4b, 0xd4, /* 168: rgb(173,  20,  90) */
    0x32, 0xc2, /* 169: rgb(132, 142, 148) */
    0xf1, 0x39, /* 170: rgb(115, 121, 140) */
    0x5b, 0x5b, /* 171: rgb(181, 210, 222) */
    0x86, 0x90, /* 172: rgb( 33,  36,  49) */
    0x8a, 0xd0, /* 173: rgb(165,  36,  82) */
    0x8c, 0xdc, /* 174: rgb(189,  36,  99) */
    0xa8, 0xa8, /* 175: rgb( 82,  45,  66) */
    0x4b, 0x58, /* 176: rgb(181,  16,  90) */
    0xbd, 0x6b, /* 177: rgb(214, 235, 239) */
    0x22, 0x04, /* 178: rgb(  8,   8,  16) */
    0x09, 0x21, /* 179: rgb( 66,  65,  74) */
    0x11, 0xb6, /* 180: rgb(107, 134, 140) */
    0x21, 0x10, /* 181: rgb( 33,   8,   8) */
    0x66, 0x2c, /* 182: rgb( 90,  24,  49) */
    0x4f, 0xf4, /* 183: rgb(239,  20, 123) */
    0x94, 0x4e, /* 184: rgb(156, 162, 165) */
    0x8e, 0xad, /* 185: rgb( 90, 101, 115) */
    0x0f, 0xed, /* 186: rgb(222,  69, 123) */
    0x2a, 0x1d, /* 187: rgb( 58,  73,  82) */
    0x8b, 0x58, /* 188: rgb(181,  32,  90) */
    0xad, 0xb5, /* 189: rgb(107, 109, 107) */
    0x2a, 0xa5, /* 190: rgb( 74,  77,  82) */
    0x0e, 0xf4, /* 191: rgb(239,   4, 115) */
    0x18, 0x5b, /* 192: rgb(181, 194, 197) */
    0x25, 0xac, /* 193: rgb( 90,  12,  41) */
    0xb6, 0xca, /* 194: rgb(148, 174, 181) */
    0xd8, 0xd6, /* 195: rgb(173, 182, 197) */
    0x2d, 0x55, /* 196: rgb(173,  73, 107) */
    0x86, 0xac, /* 197: rgb( 90,  36,  49) */
    0x5c, 0xe7, /* 198: rgb(206, 215, 230) */
    0x49, 0x44, /* 199: rgb(140,  16,  74) */
    0x44, 0x20, /* 200: rgb( 66,  16,  33) */
    0x32, 0x42, /* 201: rgb(132, 138, 148) */
    0xaf, 0xb5, /* 202: rgb(107, 109, 123) */
    0xde, 0x6f, /* 203: rgb(222, 243, 247) */
    0x9c, 0x67, /* 204: rgb(206, 227, 230) */
    0x9c, 0x6b, /* 205: rgb(214, 227, 230) */
    0x6d, 0x6c, /* 206: rgb(222,  24, 107) */
    0xa7, 0x9c, /* 207: rgb( 58,  45,  58) */
    0xc6, 0x90, /* 208: rgb( 33,  53,  49) */
    0x32, 0xb6, /* 209: rgb(107, 142, 148) */
    0x53, 0xc2, /* 210: rgb(132, 150, 156) */
    0xd0, 0xad, /* 211: rgb( 90, 117, 132) */
    0x11, 0x3a, /* 212: rgb(115, 130, 140) */
    0x2d, 0xe8, /* 213: rgb(214,  12, 107) */
    0x68, 0x3c, /* 214: rgb(123,  24,  66) */
    0xe9, 0x38, /* 215: rgb(115,  57,  74) */
    0x6b, 0xd4, /* 216: rgb(173,  28,  90) */
    0x88, 0x38, /* 217: rgb(115,  32,  66) */
    0xc7, 0x18, /* 218: rgb( 49,  49,  58) */
    0xe8, 0x18, /* 219: rgb( 49,  57,  66) */
    0x6a, 0x4c, /* 220: rgb(156,  24,  82) */
    0x2a, 0x58, /* 221: rgb(181,   8,  82) */
    0xf0, 0x74, /* 222: rgb(239,  57, 132) */
    0x9e, 0x6b, /* 223: rgb(214, 227, 247) */
    0x30, 0xf1, /* 224: rgb(230,  77, 132) */
    0x4c, 0xa9, /* 225: rgb( 82,  85,  99) */
    0x10, 0x71, /* 226: rgb(230,  65, 132) */
    0x0a, 0xb5, /* 227: rgb(107,  69,  82) */
    0x4e, 0x70, /* 228: rgb(230,  16, 115) */
    0xb6, 0x52, /* 229: rgb(165, 170, 181) */
    0xb6, 0x42, /* 230: rgb(132, 170, 181) */
    0x4c, 0xdc, /* 231: rgb(189,  20,  99) */
    0x4e, 0xd5, /* 232: rgb(173,  85, 115) */
    0x4b, 0xdc, /* 233: rgb(189,  20,  90) */
    0xf9, 0x5a, /* 234: rgb(181, 186, 206) */
    0x4c, 0x60, /* 235: rgb(197,  16,  99) */
    0x74, 0x3e, /* 236: rgb(123, 154, 165) */
    0xae, 0x29, /* 237: rgb( 82, 105, 115) */
    0x2c, 0xe4, /* 238: rgb(206,  12,  99) */
    0x87, 0x34, /* 239: rgb(107,  32,  58) */
    0xec, 0xcc, /* 240: rgb(156,  61,  99) */
    0x9f, 0xeb, /* 241: rgb(214, 231, 255) */
    0xac, 0xd8, /* 242: rgb(181,  45,  99) */
    0x09, 0xa5, /* 243: rgb( 74,  69,  74) */
    0xce, 0x39, /* 244: rgb(115, 113, 115) */
    0xef, 0x6c, /* 245: rgb(222,  57, 123) */
    0x6e, 0x70, /* 246: rgb(230,  24, 115) */
    0x5d, 0xe7, /* 247: rgb(206, 215, 239) */
    0x89, 0x44, /* 248: rgb(140,  32,  74) */
    0xab, 0xd0, /* 249: rgb(165,  45,  90) */
    0xaf, 0xf4, /* 250: rgb(239,  45, 123) */
    0x7b, 0x6b, /* 251: rgb(214, 219, 222) */
    0x0a, 0xbd, /* 252: rgb(123,  69,  82) */
    0x03, 0x1c, /* 253: rgb( 58,   0,  25) */
    0xbf, 0xeb, /* 254: rgb(214, 239, 255) */
    0x9e, 0xeb, /* 255: rgb(214, 231, 247) */
};
