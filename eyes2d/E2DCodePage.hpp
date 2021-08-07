#pragma once
#include <string>
#include <stdexcept>
#include "E2DGlobal.hpp"

namespace Eyes2D {
	namespace String {
		//std::overflow_error | Eyes2D::E2DException
		std::wstring MultiToWide(int codepage, const std::string& multi);

		//std::overflow_error | Eyes2D::E2DException
		std::string WideToMulti(int codepage, const std::wstring& wide);

		inline std::wstring UTF8ToUTF16(const std::string& utf8) {
			return std::move(MultiToWide(CP_UTF8, utf8));
		};

		inline std::string UTF16ToUTF8(const std::wstring& utf16) {
			return std::move(WideToMulti(CP_UTF8, utf16));
		}

		inline std::wstring ANSIToUTF16(const std::string& ansi) {
			return std::move(MultiToWide(CP_ACP, ansi));
		};

		inline std::string UTF16ToANSI(const std::wstring& utf16) {
			return std::move(WideToMulti(CP_ACP, utf16));
		}

		inline std::string ANSIToUTF8(const std::string& ansi) {
			return std::move(UTF16ToUTF8(ANSIToUTF16(ansi)));
		};

		inline std::string UTF8ToANSI(const std::string& utf8) {
			return std::move(UTF16ToANSI(UTF8ToUTF16(utf8)));
		}
	}
}
