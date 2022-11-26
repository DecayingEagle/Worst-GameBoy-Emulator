#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

int DisassembleGBOp(unsigned char* codebuffer, int pc) {
	unsigned char *code = &codebuffer[pc];
	int opbytes = 1;
	printf("%04x    ", pc);
	switch (*code)
	{
    case 0x00: printf("nop"); break;
    case 0x01: printf("ld bc,#$%02x%02x", code[2], code[1]); opbytes = 3; break;
    case 0x02: printf("ld [bc],a"); break;
    case 0x03: printf("inc bc"); break;
    case 0x04: printf("inc b"); break;
    case 0x05: printf("dec b"); break;
    case 0x06: printf("ld b,#$%02x", code[1]); opbytes = 2; break;
    case 0x07: printf("rlca"); break;
    case 0x08: printf("ld [#$%02x%02x],sp", code[2], code[1]); opbytes = 3; break;
    case 0x09: printf("add hl,bc"); break;
    case 0x0a: printf("ld a,[bc]"); break;
    case 0x0b: printf("dec bc"); break;
    case 0x0c: printf("inc c"); break;
    case 0x0d: printf("dec c"); break;
    case 0x0e: printf("ld c,#$%02x", code[1]); opbytes = 2; break;
    case 0x0f: printf("rrca"); break;

    case 0x10: printf("stop"); opbytes = 2; break;
    case 0x11: printf("ld de,#$%02x%02x", code[2], code[1]); opbytes = 3; break;
    case 0x12: printf("ld [de],a"); break;
    case 0x13: printf("inc de"); break;
    case 0x14: printf("inc d"); break;
    case 0x15: printf("dec d"); break;
    case 0x16: printf("ld d,#$%02x", code[1]); opbytes = 2; break;
    case 0x17: printf("rla"); break;
    case 0x18: printf("jr pc+#$%02x", code[1]); opbytes = 2; break;
    case 0x19: printf("add hl,de"); break;
    case 0x1a: printf("ld a,[de]"); break;
    case 0x1b: printf("dec de"); break;
    case 0x1c: printf("inc e"); break;
    case 0x1d: printf("dec e"); break;
    case 0x1e: printf("ld e,#$%02x", code[1]); opbytes = 2; break;
    case 0x1f: printf("rra"); break;

    case 0x20: printf("jr nz,pc+#$%02x", code[1]); opbytes = 2; break;
    case 0x21: printf("ld hl,#$%02x%02x", code[2], code[1]); opbytes = 3; break;
    case 0x22: printf("ld [hl+],a"); break;
    case 0x23: printf("inc hl"); break;
    case 0x24: printf("inc h"); break;
    case 0x25: printf("dec h"); break;
    case 0x26: printf("ld h,#$%02x", code[1]); opbytes = 2; break;
    case 0x27: printf("daa"); break;
    case 0x28: printf("jr z,pc+#$%02x", code[1]); opbytes = 2; break;
    case 0x29: printf("add hl,hl"); break;
    case 0x2a: printf("ld a,[hl+]"); break;
    case 0x2b: printf("dec hl"); break;
    case 0x2c: printf("inc l"); break;
    case 0x2d: printf("dec l"); break;
    case 0x2e: printf("ld l,#$%02x", code[1]); opbytes = 2; break;
    case 0x2f: printf("cpl"); break;

    case 0x30: printf("jr nc,pc+#$%02x", code[1]); opbytes = 2; break;
    case 0x31: printf("ld sp,#$%02x%02x", code[2], code[1]); opbytes = 3; break;
    case 0x32: printf("ld [hl-],a"); break;
    case 0x33: printf("inc sp"); break;
    case 0x34: printf("inc [hl]"); break;
    case 0x35: printf("dec [hl]"); break;
    case 0x36: printf("ld [hl],#$%02x", code[1]); opbytes = 2; break;
    case 0x37: printf("scf"); break;
    case 0x38: printf("jr c,pc+#$%02x", code[1]); opbytes = 2; break;
    case 0x39: printf("add hl,sp"); break;
    case 0x3a: printf("ld a,[hl-]"); break;
    case 0x3b: printf("dec sp"); break;
    case 0x3c: printf("inc a"); break;
    case 0x3d: printf("dec a"); break;
    case 0x3e: printf("ld a,#$%02x", code[1]); opbytes = 2; break;
    case 0x3f: printf("ccf"); break;

    case 0x40: printf("ld b,b"); break;
    case 0x41: printf("ld b,c"); break;
    case 0x42: printf("ld b,d"); break;
    case 0x43: printf("ld b,e"); break;
    case 0x44: printf("ld b,h"); break;
    case 0x45: printf("ld b,l"); break;
    case 0x46: printf("ld b,[hl]"); break;
    case 0x47: printf("ld b,a"); break;
    case 0x48: printf("ld c,b"); break;
    case 0x49: printf("ld c,c"); break;
    case 0x4a: printf("ld c,d"); break;
    case 0x4b: printf("ld c,e"); break;
    case 0x4c: printf("ld c,h"); break;
    case 0x4d: printf("ld c,l"); break;
    case 0x4e: printf("ld c,[hl]"); break;
    case 0x4f: printf("ld c,a"); break;

    case 0x50: printf("ld d,b"); break;
    case 0x51: printf("ld d,c"); break;
    case 0x52: printf("ld d,d"); break;
    case 0x53: printf("ld d,e"); break;
    case 0x54: printf("ld d,h"); break;
    case 0x55: printf("ld d,l"); break;
    case 0x56: printf("ld d,[hl]"); break;
    case 0x57: printf("ld d,a"); break;
    case 0x58: printf("ld e,b"); break;
    case 0x59: printf("ld e,c"); break;
    case 0x5a: printf("ld e,d"); break;
    case 0x5b: printf("ld e,e"); break;
    case 0x5c: printf("ld e,h"); break;
    case 0x5d: printf("ld e,l"); break;
    case 0x5e: printf("ld e,[hl]"); break;
    case 0x5f: printf("ld e,a"); break;

    case 0x60: printf("ld h,b"); break;
    case 0x61: printf("ld h,c"); break;
    case 0x62: printf("ld h,d"); break;
    case 0x63: printf("ld h,e"); break;
    case 0x64: printf("ld h,h"); break;
    case 0x65: printf("ld h,l"); break;
    case 0x66: printf("ld h,[hl]"); break;
    case 0x67: printf("ld h,a"); break;
    case 0x68: printf("ld l,b"); break;
    case 0x69: printf("ld l,c"); break;
    case 0x6a: printf("ld l,d"); break;
    case 0x6b: printf("ld l,e"); break;
    case 0x6c: printf("ld l,h"); break;
    case 0x6d: printf("ld l,l"); break;
    case 0x6e: printf("ld l,[hl]"); break;
    case 0x6f: printf("ld l,a"); break;

    case 0x70: printf("ld [hl],b"); break;
    case 0x71: printf("ld [hl],c"); break;
    case 0x72: printf("ld [hl],d"); break;
    case 0x73: printf("ld [hl],e"); break;
    case 0x74: printf("ld [hl],h"); break;
    case 0x75: printf("ld [hl],l"); break;
    case 0x76: printf("halt"); break;
    case 0x77: printf("ld [hl],a"); break;
    case 0x78: printf("ld a,b"); break;
    case 0x79: printf("ld a,c"); break;
    case 0x7a: printf("ld a,d"); break;
    case 0x7b: printf("ld a,e"); break;
    case 0x7c: printf("ld a,h"); break;
    case 0x7d: printf("ld a,l"); break;
    case 0x7e: printf("ld a,[hl]"); break;
    case 0x7f: printf("ld a,a"); break;

    case 0x80: printf("add b"); break;
    case 0x81: printf("add c"); break;
    case 0x82: printf("add d"); break;
    case 0x83: printf("add e"); break;
    case 0x84: printf("add h"); break;
    case 0x85: printf("add l"); break;
    case 0x86: printf("add [hl]"); break;
    case 0x87: printf("add a"); break;
    case 0x88: printf("adc b"); break;
    case 0x89: printf("adc c"); break;
    case 0x8a: printf("adc d"); break;
    case 0x8b: printf("adc e"); break;
    case 0x8c: printf("adc h"); break;
    case 0x8d: printf("adc l"); break;
    case 0x8e: printf("adc [hl]"); break;
    case 0x8f: printf("adc a"); break;

    case 0x90: printf("sub b"); break;
    case 0x91: printf("sub c"); break;
    case 0x92: printf("sub d"); break;
    case 0x93: printf("sub e"); break;
    case 0x94: printf("sub h"); break;
    case 0x95: printf("sub l"); break;
    case 0x96: printf("sub [hl]"); break;
    case 0x97: printf("sub a"); break;
    case 0x98: printf("sbc b"); break;
    case 0x99: printf("sbc c"); break;
    case 0x9a: printf("sbc d"); break;
    case 0x9b: printf("sbc e"); break;
    case 0x9c: printf("sbc h"); break;
    case 0x9d: printf("sbc l"); break;
    case 0x9e: printf("sbc [hl]"); break;
    case 0x9f: printf("sbc a"); break;

    case 0xa0: printf("and b"); break;
    case 0xa1: printf("and c"); break;
    case 0xa2: printf("and d"); break;
    case 0xa3: printf("and e"); break;
    case 0xa4: printf("and h"); break;
    case 0xa5: printf("and l"); break;
    case 0xa6: printf("and [hl]"); break;
    case 0xa7: printf("and a"); break;
    case 0xa8: printf("xor b"); break;
    case 0xa9: printf("xor c"); break;
    case 0xaa: printf("xor d"); break;
    case 0xab: printf("xor e"); break;
    case 0xac: printf("xor h"); break;
    case 0xad: printf("xor l"); break;
    case 0xae: printf("xor [hl]"); break;
    case 0xaf: printf("xor a"); break;

    case 0xb0: printf("or b"); break;
    case 0xb1: printf("or c"); break;
    case 0xb2: printf("or d"); break;
    case 0xb3: printf("or e"); break;
    case 0xb4: printf("or h"); break;
    case 0xb5: printf("or l"); break;
    case 0xb6: printf("or [hl]"); break;
    case 0xb7: printf("or a"); break;
    case 0xb8: printf("cp b"); break;
    case 0xb9: printf("cp c"); break;
    case 0xba: printf("cp d"); break;
    case 0xbb: printf("cp e"); break;
    case 0xbc: printf("cp h"); break;
    case 0xbd: printf("cp l"); break;
    case 0xbe: printf("cp [hl]"); break;
    case 0xbf: printf("cp a"); break;

    case 0xc0: printf("ret nz"); break;
    case 0xc1: printf("pop bc"); break;
    case 0xc2: printf("jp nz,#$%02x%02x", code[2], code[1]); opbytes = 3; break;
    case 0xc3: printf("jp #$%02x%02x", code[2], code[1]); opbytes = 3; break;
    case 0xc4: printf("call nz,#$%02x%02x", code[2], code[1]); opbytes = 3; break;
    case 0xc5: printf("push bc"); break;
    case 0xc6: printf("add #$%02x", code[1]); opbytes = 2; break;
    case 0xc7: printf("rst $00"); break;
    case 0xc8: printf("ret z"); break;
    case 0xc9: printf("ret"); break;
    case 0xca: printf("jp z,#$%02x%02x", code[2], code[1]); opbytes = 3; break;
    case 0xcb: 
        printf("CBPREFIX "); opbytes = 2;
        switch (code[1])
        {
        case 0x00: printf("rlc b"); break;
        case 0x01: printf("rlc c"); break;
        case 0x02: printf("rlc d"); break;
        case 0x03: printf("rlc e"); break;
        case 0x04: printf("rlc h"); break;
        case 0x05: printf("rlc l"); break;
        case 0x06: printf("rlc [hl]"); break;
        case 0x07: printf("rlc a"); break;
        case 0x08: printf("rrc b"); break;
        case 0x09: printf("rrc c"); break;
        case 0x0a: printf("rrc d"); break;
        case 0x0b: printf("rrc e"); break;
        case 0x0c: printf("rrc h"); break;
        case 0x0d: printf("rrc l"); break;
        case 0x0e: printf("rrc [hl]"); break;
        case 0x0f: printf("rrc a"); break;

        case 0x10: printf("rl b"); break;
        case 0x11: printf("rl c"); break;
        case 0x12: printf("rl d"); break;
        case 0x13: printf("rl e"); break;
        case 0x14: printf("rl h"); break;
        case 0x15: printf("rl l"); break;
        case 0x16: printf("rl [hl]"); break;
        case 0x17: printf("rl a"); break;
        case 0x18: printf("rr b"); break;
        case 0x19: printf("rr c"); break;
        case 0x1a: printf("rr d"); break;
        case 0x1b: printf("rr e"); break;
        case 0x1c: printf("rr h"); break;
        case 0x1d: printf("rr l"); break;
        case 0x1e: printf("rr [hl]"); break;
        case 0x1f: printf("rr a"); break;

        case 0x20: printf("sla b"); break;
        case 0x21: printf("sla c"); break;
        case 0x22: printf("sla d"); break;
        case 0x23: printf("sla e"); break;
        case 0x24: printf("sla h"); break;
        case 0x25: printf("sla l"); break;
        case 0x26: printf("sla [hl]"); break;
        case 0x27: printf("sla a"); break;
        case 0x28: printf("sra b"); break;
        case 0x29: printf("sra c"); break;
        case 0x2a: printf("sra d"); break;
        case 0x2b: printf("sra e"); break;
        case 0x2c: printf("sra h"); break;
        case 0x2d: printf("sra l"); break;
        case 0x2e: printf("sra [hl]"); break;
        case 0x2f: printf("sra a"); break;

        case 0x30: printf("swap b"); break;
        case 0x31: printf("swap c"); break;
        case 0x32: printf("swap d"); break;
        case 0x33: printf("swap e"); break;
        case 0x34: printf("swap h"); break;
        case 0x35: printf("swap l"); break;
        case 0x36: printf("swap [hl]"); break;
        case 0x37: printf("swap a"); break;
        case 0x38: printf("srl b"); break;
        case 0x39: printf("srl c"); break;
        case 0x3a: printf("srl d"); break;
        case 0x3b: printf("srl e"); break;
        case 0x3c: printf("srl h"); break;
        case 0x3d: printf("srl l"); break;
        case 0x3e: printf("srl [hl]"); break;
        case 0x3f: printf("srl a"); break;

        case 0x40: printf("bit 0,b"); break;
        case 0x41: printf("bit 0,c"); break;
        case 0x42: printf("bit 0,d"); break;
        case 0x43: printf("bit 0,e"); break;
        case 0x44: printf("bit 0,h"); break;
        case 0x45: printf("bit 0,l"); break;
        case 0x46: printf("bit 0,[hl]"); break;
        case 0x47: printf("bit 0,a"); break;
        case 0x48: printf("bit 1,b"); break;
        case 0x49: printf("bit 1,c"); break;
        case 0x4a: printf("bit 1,d"); break;
        case 0x4b: printf("bit 1,e"); break;
        case 0x4c: printf("bit 1,h"); break;
        case 0x4d: printf("bit 1,l"); break;
        case 0x4e: printf("bit 1,[hl]"); break;
        case 0x4f: printf("bit 1,a"); break;

        case 0x50: printf("bit 2,b"); break;
        case 0x51: printf("bit 2,c"); break;
        case 0x52: printf("bit 2,d"); break;
        case 0x53: printf("bit 2,e"); break;
        case 0x54: printf("bit 2,h"); break;
        case 0x55: printf("bit 2,l"); break;
        case 0x56: printf("bit 2,[hl]"); break;
        case 0x57: printf("bit 2,a"); break;
        case 0x58: printf("bit 3,b"); break;
        case 0x59: printf("bit 3,c"); break;
        case 0x5a: printf("bit 3,d"); break;
        case 0x5b: printf("bit 3,e"); break;
        case 0x5c: printf("bit 3,h"); break;
        case 0x5d: printf("bit 3,l"); break;
        case 0x5e: printf("bit 3,[hl]"); break;
        case 0x5f: printf("bit 3,a"); break;

        case 0x60: printf("bit 4,b"); break;
        case 0x61: printf("bit 4,c"); break;
        case 0x62: printf("bit 4,d"); break;
        case 0x63: printf("bit 4,e"); break;
        case 0x64: printf("bit 4,h"); break;
        case 0x65: printf("bit 4,l"); break;
        case 0x66: printf("bit 4,[hl]"); break;
        case 0x67: printf("bit 4,a"); break;
        case 0x68: printf("bit 5,b"); break;
        case 0x69: printf("bit 5,c"); break;
        case 0x6a: printf("bit 5,d"); break;
        case 0x6b: printf("bit 5,e"); break;
        case 0x6c: printf("bit 5,h"); break;
        case 0x6d: printf("bit 5,l"); break;
        case 0x6e: printf("bit 5,[hl]"); break;
        case 0x6f: printf("bit 5,a"); break;

        case 0x70: printf("bit 6,b"); break;
        case 0x71: printf("bit 6,c"); break;
        case 0x72: printf("bit 6,d"); break;
        case 0x73: printf("bit 6,e"); break;
        case 0x74: printf("bit 6,h"); break;
        case 0x75: printf("bit 6,l"); break;
        case 0x76: printf("bit 6,[hl]"); break;
        case 0x77: printf("bit 6,a"); break;
        case 0x78: printf("bit 7,b"); break;
        case 0x79: printf("bit 7,c"); break;
        case 0x7a: printf("bit 7,d"); break;
        case 0x7b: printf("bit 7,e"); break;
        case 0x7c: printf("bit 7,h"); break;
        case 0x7d: printf("bit 7,l"); break;
        case 0x7e: printf("bit 7,[hl]"); break;
        case 0x7f: printf("bit 7,a"); break;

        case 0x80: printf("res 0,b"); break;
        case 0x81: printf("res 0,c"); break;
        case 0x82: printf("res 0,d"); break;
        case 0x83: printf("res 0,e"); break;
        case 0x84: printf("res 0,h"); break;
        case 0x85: printf("res 0,l"); break;
        case 0x86: printf("res 0,[hl]"); break;
        case 0x87: printf("res 0,a"); break;
        case 0x88: printf("res 1,b"); break;
        case 0x89: printf("res 1,c"); break;
        case 0x8a: printf("res 1,d"); break;
        case 0x8b: printf("res 1,e"); break;
        case 0x8c: printf("res 1,h"); break;
        case 0x8d: printf("res 1,l"); break;
        case 0x8e: printf("res 1,[hl]"); break;
        case 0x8f: printf("res 1,a"); break;

        case 0x90: printf("res 2,b"); break;
        case 0x91: printf("res 2,c"); break;
        case 0x92: printf("res 2,d"); break;
        case 0x93: printf("res 2,e"); break;
        case 0x94: printf("res 2,h"); break;
        case 0x95: printf("res 2,l"); break;
        case 0x96: printf("res 2,[hl]"); break;
        case 0x97: printf("res 2,a"); break;
        case 0x98: printf("res 3,b"); break;
        case 0x99: printf("res 3,c"); break;
        case 0x9a: printf("res 3,d"); break;
        case 0x9b: printf("res 3,e"); break;
        case 0x9c: printf("res 3,h"); break;
        case 0x9d: printf("res 3,l"); break;
        case 0x9e: printf("res 3,[hl]"); break;
        case 0x9f: printf("res 3,a"); break;

        case 0xa0: printf("res 4,b"); break;
        case 0xa1: printf("res 4,c"); break;
        case 0xa2: printf("res 4,d"); break;
        case 0xa3: printf("res 4,e"); break;
        case 0xa4: printf("res 4,h"); break;
        case 0xa5: printf("res 4,l"); break;
        case 0xa6: printf("res 4,[hl]"); break;
        case 0xa7: printf("res 4,a"); break;
        case 0xa8: printf("res 5,b"); break;
        case 0xa9: printf("res 5,c"); break;
        case 0xaa: printf("res 5,d"); break;
        case 0xab: printf("res 5,e"); break;
        case 0xac: printf("res 5,h"); break;
        case 0xad: printf("res 5,l"); break;
        case 0xae: printf("res 5,[hl]"); break;
        case 0xaf: printf("res 5,a"); break;

        case 0xb0: printf("res 6,b"); break;
        case 0xb1: printf("res 6,c"); break;
        case 0xb2: printf("res 6,d"); break;
        case 0xb3: printf("res 6,e"); break;
        case 0xb4: printf("res 6,h"); break;
        case 0xb5: printf("res 6,l"); break;
        case 0xb6: printf("res 6,[hl]"); break;
        case 0xb7: printf("res 6,a"); break;
        case 0xb8: printf("res 7,b"); break;
        case 0xb9: printf("res 7,c"); break;
        case 0xba: printf("res 7,d"); break;
        case 0xbb: printf("res 7,e"); break;
        case 0xbc: printf("res 7,h"); break;
        case 0xbd: printf("res 7,l"); break;
        case 0xbe: printf("res 7,[hl]"); break;
        case 0xbf: printf("res 7,a"); break;


        case 0xc0: printf("set 0,b"); break;
        case 0xc1: printf("set 0,c"); break;
        case 0xc2: printf("set 0,d"); break;
        case 0xc3: printf("set 0,e"); break;
        case 0xc4: printf("set 0,h"); break;
        case 0xc5: printf("set 0,l"); break;
        case 0xc6: printf("set 0,[hl]"); break;
        case 0xc7: printf("set 0,a"); break;
        case 0xc8: printf("set 1,b"); break;
        case 0xc9: printf("set 1,c"); break;
        case 0xca: printf("set 1,d"); break;
        case 0xcb: printf("set 1,e"); break;
        case 0xcc: printf("set 1,h"); break;
        case 0xcd: printf("set 1,l"); break;
        case 0xce: printf("set 1,[hl]"); break;
        case 0xcf: printf("set 1,a"); break;

        case 0xd0: printf("set 2,b"); break;
        case 0xd1: printf("set 2,c"); break;
        case 0xd2: printf("set 2,d"); break;
        case 0xd3: printf("set 2,e"); break;
        case 0xd4: printf("set 2,h"); break;
        case 0xd5: printf("set 2,l"); break;
        case 0xd6: printf("set 2,[hl]"); break;
        case 0xd7: printf("set 2,a"); break;
        case 0xd8: printf("set 3,b"); break;
        case 0xd9: printf("set 3,c"); break;
        case 0xda: printf("set 3,d"); break;
        case 0xdb: printf("set 3,e"); break;
        case 0xdc: printf("set 3,h"); break;
        case 0xdd: printf("set 3,l"); break;
        case 0xde: printf("set 3,[hl]"); break;
        case 0xdf: printf("set 3,a"); break;

        case 0xe0: printf("set 4,b"); break;
        case 0xe1: printf("set 4,c"); break;
        case 0xe2: printf("set 4,d"); break;
        case 0xe3: printf("set 4,e"); break;
        case 0xe4: printf("set 4,h"); break;
        case 0xe5: printf("set 4,l"); break;
        case 0xe6: printf("set 4,[hl]"); break;
        case 0xe7: printf("set 4,a"); break;
        case 0xe8: printf("set 5,b"); break;
        case 0xe9: printf("set 5,c"); break;
        case 0xea: printf("set 5,d"); break;
        case 0xeb: printf("set 5,e"); break;
        case 0xec: printf("set 5,h"); break;
        case 0xed: printf("set 5,l"); break;
        case 0xee: printf("set 5,[hl]"); break;
        case 0xef: printf("set 5,a"); break;

        case 0xf0: printf("set 6,b"); break;
        case 0xf1: printf("set 6,c"); break;
        case 0xf2: printf("set 6,d"); break;
        case 0xf3: printf("set 6,e"); break;
        case 0xf4: printf("set 6,h"); break;
        case 0xf5: printf("set 6,l"); break;
        case 0xf6: printf("set 6,[hl]"); break;
        case 0xf7: printf("set 6,a"); break;
        case 0xf8: printf("set 7,b"); break;
        case 0xf9: printf("set 7,c"); break;
        case 0xfa: printf("set 7,d"); break;
        case 0xfb: printf("set 7,e"); break;
        case 0xfc: printf("set 7,h"); break;
        case 0xfd: printf("set 7,l"); break;
        case 0xfe: printf("set 7,[hl]"); break;
        case 0xff: printf("set 7,a"); break;
        default:
            printf("invalid cb"); break;
        } break;
    case 0xcc: printf("call z,#$%02x%02x", code[2], code[1]); opbytes = 3; break;
    case 0xcd: printf("call #$%02x%02x", code[2], code[1]); opbytes = 3; break;
    case 0xce: printf("adc #$%02x", code[1]); opbytes = 2; break;
    case 0xcf: printf("rst $08"); break;

    case 0xd0: printf("ret nc"); break;
    case 0xd1: printf("pop de"); break;
    case 0xd2: printf("jp nc,#$%02x%02x", code[2], code[1]); opbytes = 3; break;
    case 0xd3: printf("db $d3"); break;
    case 0xd4: printf("call nc,#$%02x%02x", code[2], code[1]); opbytes = 3; break;
    case 0xd5: printf("push de"); break;
    case 0xd6: printf("sub #$%02x", code[1]); opbytes = 2; break;
    case 0xd7: printf("rst $10"); break;
    case 0xd8: printf("ret c"); break;
    case 0xd9: printf("reti"); break;
    case 0xda: printf("jp c,#$%02x%02x", code[2], code[1]); opbytes = 3; break;
    case 0xdb: printf("db $db"); break;
    case 0xdc: printf("call c,#$%02x%02x", code[2], code[1]); opbytes = 3; break;
    case 0xdd: printf("db $dd"); break;
    case 0xde: printf("sbc #$%02x", code[1]); opbytes = 2; break;
    case 0xdf: printf("rst $18"); break;

    case 0xe0: printf("ldh [#$%02x],a", code[1]); opbytes = 2; break;
    case 0xe1: printf("pop hl"); break;
    case 0xe2: printf("ld [#$%02x],a", code[1]); opbytes = 2; break;
    case 0xe3: printf("db $e3"); break;
    case 0xe4: printf("db $e4"); break;
    case 0xe5: printf("push hl"); break;
    case 0xe6: printf("and #$%02x", code[1]); opbytes = 2; break;
    case 0xe7: printf("rst $20"); break;
    case 0xe8: printf("add sp,#$%02x", code[1]); opbytes = 2; break;
    case 0xe9: printf("jp hl"); break;
    case 0xea: printf("ld [#$%02x%02x],a", code[1], code[2]); break;
    case 0xeb: printf("db $eb"); break;
    case 0xec: printf("db $ec"); break;
    case 0xed: printf("db $ed"); break;
    case 0xee: printf("xor #$%02x", code[1]); opbytes = 2; break;
    case 0xef: printf("rst $28"); break;

    case 0xf0: printf("ldh a,[#$%02x]", code[1]); opbytes = 2; break;
    case 0xf1: printf("pop af"); break;
    case 0xf2: printf("ld a,[#$%02x]", code[1]); opbytes = 2; break;
    case 0xf3: printf("di"); break;
    case 0xf4: printf("db $f4"); break;
    case 0xf5: printf("push af"); break;
    case 0xf6: printf("or #$%02x", code[1]); opbytes = 2; break;
    case 0xf7: printf("rst $30"); break;
    case 0xf8: printf("ld hl,sp+#$%02x", code[1]); opbytes = 2; break;
    case 0xf9: printf("ld sp,hl"); break;
    case 0xfa: printf("ld a,#$%02x%02x", code[2], code[1]); opbytes = 3; break;
    case 0xfb: printf("ei"); break;
    case 0xfc: printf("db $fc"); break;
    case 0xfd: printf("db $fd"); break;
    case 0xfe: printf("cp #$%02x", code[1]); opbytes = 2; break;
    case 0xff: printf("rst $38"); break;

	default:
        printf("invalid"); break;
	}
    printf("\n");

    return opbytes;
}

typedef struct ConditionCodes {
    char    z : 1;
    char    n : 1;
    char    h : 1;
    char    c : 1;
} ConditionCodes;

typedef struct StateCPU {
    struct {
		union {
			struct {
				uint8_t f;
				uint8_t a;
			};
			uint16_t af;
		};
	};
	struct {
		union {
			struct {
				uint8_t c;
				uint8_t b;
			};
			uint16_t bc;
		};
	};
	struct {
		union {
			struct {
				uint8_t e;
				uint8_t d;
			};
			uint16_t de;
		};
	};
	struct {
		union {
			struct {
				uint8_t l;
				uint8_t h;
			};
			uint16_t hl;
		};
	};
    uint16_t    sp;
    uint16_t    pc;
    uint8_t* memory;
    bool sysClkActive;
    bool mainClkActive;
    struct      ConditionCodes      cc;
} StateCPU;

void UnimplementedInstruction(StateCPU* state)
{
    //pc will have advanced one, so undo that    
    printf("Error: Unimplemented instruction\n");
    exit(1);
}

int EmulateGBOp(StateCPU* state)
{
    unsigned char* opcode = &state->memory[state->pc];
    int cycles = 1;

    switch (*opcode)
    {
    case 0x00: break; // nop
    case 0x01: { // ld bc,d16
        state->bc = ((opcode[2]<<8)|opcode[1]);
        cycles = 3;
        break;
    }
    case 0x02: { // ld (bc),a
        state->memory[state->bc] = state->a;
        cycles = 2;
        break;
    }
    case 0x03: { // inc bc
        uint32_t answer = (uint32_t)state->bc + 1;
        state->bc = (answer & 0xffff);
        cycles = 2;
        break;
    }
    case 0x04: { // inc b
        uint16_t answer = (uint16_t)state->b + 1;
        state->cc.z = ((answer ^ 0x0) == 0);
        state->cc.n = 0;
        state->cc.h = ((answer & 0x8) != 0);
        state->b = (answer & 0xff);
        break;
    }
    case 0x05: { // dec b
        uint16_t answer = (uint16_t)state->b - 1;
        state->cc.z = ((answer ^ 0x0) == 0);
        state->cc.n = 1;
        state->cc.h = ((answer & 0xf) != 0);
        state->b = (answer & 0xff);
        break;
    }
    case 0x06: { // ld b,d8
        state->b = opcode[1];
        cycles = 2;
        break;
    }
    case 0x07: { // rlca
        uint16_t answer = ((uint16_t)state->a<<1);
        state->cc.z = ((answer ^ 0x0) == 0);
        state->cc.n = 0;
        state->cc.h = 0;
        state->cc.c = ((answer & 0x100) == 0x100);
        state->a = (answer & 0xff);
        break;
    }
    case 0x08: { // ld (d16),sp
        state->memory[(opcode[1]<<8)|opcode[2]] = state->sp;
        cycles = 5;
        break;
    }
    case 0x09: { // add hl,bc
        uint32_t answer = (uint32_t)state->hl + (uint32_t)state->bc;
        state->cc.n = 0;
        state->cc.h = ((answer & 0x1000) != 0);
        state->cc.c = ((answer & 0xffff) == 0);
        state->hl = (answer & 0xffff);
        cycles = 2;
        break;
    }
    case 0x0a: { // ld a,(bc)
        state->a = state->memory[state->bc];
        cycles = 2;
        break;
    }
    case 0x0b: { // dec bc
        uint32_t answer = (uint32_t)state->bc - 1;
        state->bc = (answer & 0xffff);
        cycles = 2;
        break;
    }
    case 0x0c: { // inc c
        uint16_t answer = (uint16_t)state->c + 1;
        state->cc.z = ((answer ^ 0x0) == 0);
        state->cc.n = 0;
        state->cc.h = ((answer & 0x8) != 0);
        state->c = (answer & 0xff);
        break;
    }
    case 0x0d: { // dec c
        uint16_t answer = (uint16_t)state->c - 1;
        state->cc.z = ((answer ^ 0x0) == 0);
        state->cc.n = 1;
        state->cc.h = ((answer & 0xf) != 0);
        state->c = (answer & 0xff);
        break;
    }
    case 0x0e: { // ld c,d8
        state->c = opcode[1];
        cycles = 2;
        break;
    }
    case 0x0f: { // rrca
        uint16_t answer = ((uint16_t)state->a>>1);
        state->cc.z = ((answer ^ 0x0) == 0);
        state->cc.n = 0;
        state->cc.h = 0;
        state->cc.c = ((answer & 0x100) == 0x100);
        state->a = (answer & 0xff);
        break;
    }

    case 0x10: { // stop 
        UnimplementedInstruction(state); //TODO:when i implement IO 
        // sysClkActive = 0;
        // mainClkActive = 0;
        // if io then {
        //    sysClkActive = 1;
        //    mainClkActive = 1;
        //}
        break;
    }
    case 0x11: { // ld de,d16
        state->de = ((opcode[2]<<8)|opcode[1]);
        cycles = 3;
        break;
    }
    case 0x12: { // ld (de),a
        state->memory[state->de] = state->a;
        cycles = 2;
        break;
    }
    case 0x13: { // inc de
        uint32_t answer = (uint32_t)state->de + 1;
        state->de = (answer & 0xffff);
        cycles = 2;
        break;
    }
    case 0x14: { // inc d
        uint16_t answer = (uint16_t)state->d + 1;
        state->cc.z = ((answer ^ 0x0) == 0);
        state->cc.n = 0;
        state->cc.h = ((answer & 0x8) != 0);
        state->d = (answer & 0xff);
        break;
    }
    case 0x15: { // dec d
        uint16_t answer = (uint16_t)state->d - 1;
        state->cc.z = ((answer ^ 0x0) == 0);
        state->cc.n = 1;
        state->cc.h = ((answer & 0xf) != 0);
        state->d = (answer & 0xff);
        break;
    }
    case 0x16: { // ld d,d8
        state->d = opcode[1];
        cycles = 2;
        break;
    }
    case 0x17: { // rla  //! might be different from rlca
        uint16_t answer = ((uint16_t)state->a<<1);
        state->cc.z = ((answer ^ 0x0) == 0);
        state->cc.n = 0;
        state->cc.h = 0;
        state->cc.c = ((answer & 0x100) == 0x100);
        state->a = (answer & 0xff);
        break;
    }
    case 0x18: { // jr r8
        state->pc += opcode[1];
        break;
    }
    case 0x19: { // add hl,de
        uint32_t answer = (uint32_t)state->hl + (uint32_t)state->de;
        state->cc.n = 0;
        state->cc.h = ((answer & 0x1000) != 0);
        state->cc.c = ((answer & 0xffff) == 0);
        state->hl = (answer & 0xffff);
        cycles = 2;
        break;
    }
    case 0x1a: { // ld a,(de)
        state->a = state->memory[state->de];
        cycles = 2;
        break;
    }
    case 0x1b: { // dec de
        uint32_t answer = (uint32_t)state->de - 1;
        state->de = (answer & 0xffff);
        cycles = 2;
        break;
    }
    case 0x1c: { // inc e
        uint16_t answer = (uint16_t)state->e + 1;
        state->cc.z = ((answer ^ 0x0) == 0);
        state->cc.n = 0;
        state->cc.h = ((answer & 0x8) != 0);
        state->e = (answer & 0xff);
        break;
    }
    case 0x1d: { // dec e
        uint16_t answer = (uint16_t)state->e - 1;
        state->cc.z = ((answer ^ 0x0) == 0);
        state->cc.n = 1;
        state->cc.h = ((answer & 0xf) != 0);
        state->e = (answer & 0xff);
        break;
    }
    case 0x1e: { // ld e,d8
        state->e = opcode[1];
        cycles = 2;
        break;
    }
    case 0x1f: { // rra //! might be different from rrca
        uint16_t answer = ((uint16_t)state->a>>1);
        state->cc.z = ((answer ^ 0x0) == 0);
        state->cc.n = 0;
        state->cc.h = 0;
        state->cc.c = ((answer & 0x100) == 0x100);
        state->a = (answer & 0xff);
        break;
    }
    case 0x20: { // jr nz,r8
        if(!(state->cc.z)){
            state->pc += opcode[1];
            cycles = 3;
            break;
        } else {
            cycles = 2;
            break;
        }
    }
    case 0x21: { // ld hl,d16
        state->hl = ((opcode[2]<<8)|opcode[1]);
        cycles = 3;
        break;
    }
    case 0x22: { //TODO: ld (hl+),d16 mnemonic: ld a,(hli) or ldi a,(hl)
        UnimplementedInstruction(state);
    }
    case 0x24: { // inc h
        uint16_t answer = (uint16_t)state->h + 1;
        state->cc.z = ((answer ^ 0x0) == 0);
        state->cc.n = 0;
        state->cc.h = ((answer & 0x8) != 0);
        state->h = (answer & 0xff);
        break;
    }
    case 0x25: { // dec h
        uint16_t answer = (uint16_t)state->h - 1;
        state->cc.z = ((answer ^ 0x0) == 0);
        state->cc.n = 1;
        state->cc.h = ((answer & 0xf) != 0);
        state->h = (answer & 0xff);
        break;
    }
    case 0x26: { // ld h,d8
        state->h = opcode[1];
        cycles = 2;
        break;
    }
    case 0x27: { // daa
        UnimplementedInstruction(state);
        break;
    }
    case 0x28: { // jr z,d8
        if(state->cc.z){
            state->pc += opcode[1];
            cycles = 3;
            break;
        } else {
            cycles = 2;
            break;
        }
    }
    case 0x29: { // add hl,hl
        uint32_t answer = (uint32_t)state->hl + (uint32_t)state->hl;
        state->cc.n = 0;
        state->cc.h = ((answer & 0x1000 != 0));
        state->cc.c = ((answer & 0xffff == 0));
        state->hl = (answer & 0xffff);
        cycles = 2;
        break;
    }
    case 0x2a: { // ld a,[hl+] //TODO
        UnimplementedInstruction(state);
        cycles = 2;
        break;
    }
    case 0x2b: { // dec hl
        uint32_t answer = (uint32_t)state->hl - 1;
        state->hl = (answer && 0xffff);
        cycles = 2;
        break;
    }
    case 0x2c: { // inc l
        uint16_t answer = (uint16_t)state->l + 1;
        state->cc.z = ((answer ^ 0x0) == 0);
        state->cc.n = 0;
        state->cc.h = ((answer & 0xf) != 0);
        state->l = (answer & 0xff);
    }

    default: {
        UnimplementedInstruction(state);
        break;
    }
    }

    state->pc += 1;  //for the opcode    
}

int main(int argc, char** argv) {
    FILE* f = fopen(argv[1], "rb");
    if (f == NULL)
    {
        printf("error: Couldn't open %s\n", argv[1]);
        exit(1);
    };
    //Get the file size and read it into a memory buffer    
    fseek(f, 0L, SEEK_END);
    int fsize = ftell(f);
    fseek(f, 0L, SEEK_SET);

    unsigned char* buffer = malloc(fsize);

    fread(buffer, fsize, 1, f);
    fclose(f);

    int pc = 0;

    while (pc < fsize)
    {
        pc += DisassembleGBOp(buffer, pc);
    }
    return 0;
}
