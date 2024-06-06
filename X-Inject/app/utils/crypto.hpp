#pragma once

#include "error.hpp"

#include <iostream>
#include <Windows.h>
#include <vector>

namespace Crypto {
    std::string Base64Decode(std::string EncodedStr) {
        DWORD decodedSize = 0;

        // ��ȡ���������ݴ�С
        if (!CryptStringToBinaryA(EncodedStr.c_str(), 0, CRYPT_STRING_BASE64, nullptr, &decodedSize, nullptr, nullptr)) {
            Error::WarnMsgBox(L"CryptStringToBinary failed");
            return "";
        }

        std::vector<BYTE> decodedData(decodedSize);

        // ����
        if (!CryptStringToBinaryA(EncodedStr.c_str(), 0, CRYPT_STRING_BASE64, decodedData.data(), &decodedSize, nullptr, nullptr)) {
            Error::WarnMsgBox(L"CryptStringToBinary failed");
            return "";
        }
        return std::string(decodedData.begin(), decodedData.end());
    }
}