#pragma once

typedef struct
{
	u64 size;
	u8 *buffer;
} buffer_struct;

// Memory
void endian_memcpy(u8 *destination, u8 *source, u32 size, int endianness);
int CopyData(u8 **dest, u8 *source, u64 size);
void rndset(void *ptr, u64 num);
void clrmem(void *ptr, u64 num);

// MISC
u64 roundup(u64 value, u64 alignment);
u64 align(u64 value, u64 alignment);
u64 min64(u64 a, u64 b);
u64 max64(u64 a, u64 b);

// Strings
void memdump(FILE* fout, const char* prefix, const u8* data, u32 size);
int append_filextention(char *output, u16 max_outlen, char *input, char extention[]);
int str_u8_to_u16(u16 **dst, u32 *dst_len, u8 *src, u32 src_len);
int str_u16_to_u16(u16 **dst, u32 *dst_len, u16 *src, u32 src_len);
int str_u32_to_u16(u16 **dst, u32 *dst_len, u32 *src, u32 src_len);
#ifndef _WIN32
int str_utf8_to_u16(u16 **dst, u32 *dst_len, u8 *src, u32 src_len);
#endif

// Base64
bool IsValidB64Char(char chr);
u32 b64_strlen(char *str);
void b64_strcpy(char *dst, char *src);
int b64_decode(u8 *dst, char *src, u32 dst_size);

// Pseudo-Random Number Generator
void initRand(void);
u8 u8GetRand(void);
u16 u16GetRand(void);
u32 u32GetRand(void);
u64 u64GetRand(void);

//Char IO
bool AssertFile(char *filename);
u64 GetFileSize64(char *filename);
int makedir(const char* dir);
char *getcwdir(char *buffer,int maxlen);
int TruncateFile64(char *filename, u64 filelen);

//Wide Char IO
#ifdef _WIN32
u64 wGetFileSize64(u16 *filename);
#endif

//IO Misc
u8* ImportFile(char *file, u64 size);
void WriteBuffer(void *buffer, u64 size, u64 offset, FILE *output);
void ReadFile64(void *outbuff, u64 size, u64 offset, FILE *file);
int fseek_64(FILE *fp, u64 file_pos);

//Data Size conversion
u16 u8_to_u16(u8 *value, u8 endianness);
u32 u8_to_u32(u8 *value, u8 endianness);
u64 u8_to_u64(u8 *value, u8 endianness);
int u16_to_u8(u8 *out_value, u16 in_value, u8 endianness);
int u32_to_u8(u8 *out_value, u32 in_value, u8 endianness);
int u64_to_u8(u8 *out_value, u64 in_value, u8 endianness);


