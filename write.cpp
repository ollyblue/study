/*
 * =====================================================================================
 *
 *       Filename:  write.cpp
 *
 *    Description:  for test write
 *
 *        Version:  1.0
 *        Created:  03/24/2014 02:30:53 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  bluezheng (bluezheng@tencent.com)
 *        Company:  Tencent
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <string>
#include <stdint.h>
#include <stdarg.h>

std::string Write(const std::string& strFile,
				const std::string& strFunction,
				const uint32_t dwLine,
				const char* strFormat,
				...);


int main(int argc, const char *argv[])
{
	uint32_t a = 100;
	uint32_t b = 2;
	std::string strRes = Write(__FILE__, __func__, __LINE__, "a:%u b:%u",
	a,b);
	printf("res:%s\n", strRes.c_str());
	
	return 0;
}

std::string Write(const std::string& strFile,
				const std::string& strFunction,
				const uint32_t dwLine,
				const char* strFormat,
				...)
{
	std::string strRes;
	if( ! strFormat )
	{
		return strRes;
	}
	char szBuff[4096] = { 0 };
	snprintf(szBuff, sizeof(szBuff), "[%s:%u] [%s]",
	strFile.c_str(), dwLine, strFunction.c_str());
	size_t dwLen = strnlen(szBuff,sizeof(szBuff));

	va_list ap;
	va_start(ap,strFormat);
	vsnprintf(szBuff + dwLen, sizeof(szBuff) - dwLen, strFormat, ap);
	va_end(ap);
	strRes = szBuff;
	return strRes;
}
