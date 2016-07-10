//
// Copyright 2016 David Roller
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//  http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
#include <windows.h>
#include <iostream>
#include <tchar.h>
#include <sstream>

///////////////////////////////////////////////////////////////////////////////
/// Main function for the file attributes tool
///////////////////////////////////////////////////////////////////////////////
int _tmain(int argc, _TCHAR* argv[])
{
    if (argc >= 2)
    {
        BOOL res = FALSE;
        std::wstring FileName = argv[2];
        DWORD attrib = ::GetFileAttributesW(FileName.c_str());

        if (wcscmp(argv[1], L"set") == 0)
        {
            for (int i = 3; i != argc; ++i)
            {
                DWORD addAttrib = 0;
                std::wistringstream ss(argv[3]);
                ss >> addAttrib;

                if (addAttrib > 0)
                {
                    attrib |= addAttrib;
                }
            }

            res = ::SetFileAttributesW(FileName.c_str(), attrib);
        }
        else if (wcscmp(argv[1], L"get") == 0)
        {
            std::wcout << std::hex << attrib << std::endl;
            res = TRUE;
        }

        if (res == TRUE)
        {
            return 0;
        }
    }

    std::wcout << L"Usage: \tFileAttribTool.exe [get|set] [FileName] [AttribNum]" << std::endl;
    std::wcout << L"\t[AttribNum]:" << std::endl;
    std::wcout << L"\t - 1:        FILE_ATTRIBUTE_READONLY             0x00000001" << std::endl;
    std::wcout << L"\t - 2:        FILE_ATTRIBUTE_HIDDEN               0x00000002" << std::endl;
    std::wcout << L"\t - 4:        FILE_ATTRIBUTE_SYSTEM               0x00000004" << std::endl;
    std::wcout << L"\t - 16:       FILE_ATTRIBUTE_DIRECTORY            0x00000010" << std::endl;
    std::wcout << L"\t - 32:       FILE_ATTRIBUTE_ARCHIVE              0x00000020" << std::endl;
    std::wcout << L"\t - 64:       FILE_ATTRIBUTE_DEVICE               0x00000040" << std::endl;
    std::wcout << L"\t - 128:      FILE_ATTRIBUTE_NORMAL               0x00000080" << std::endl;
    std::wcout << L"\t - 256:      FILE_ATTRIBUTE_TEMPORARY            0x00000100" << std::endl;
    std::wcout << L"\t - 512:      FILE_ATTRIBUTE_SPARSE_FILE          0x00000200" << std::endl;
    std::wcout << L"\t - 1024:     FILE_ATTRIBUTE_REPARSE_POINT        0x00000400" << std::endl;
    std::wcout << L"\t - 2048:     FILE_ATTRIBUTE_COMPRESSED           0x00000800" << std::endl;
    std::wcout << L"\t - 4096:     FILE_ATTRIBUTE_OFFLINE              0x00001000" << std::endl;
    std::wcout << L"\t - 8192:     FILE_ATTRIBUTE_NOT_CONTENT_INDEXED  0x00002000" << std::endl;
    std::wcout << L"\t - 16384:    FILE_ATTRIBUTE_ENCRYPTED            0x00004000" << std::endl;
    std::wcout << L"\t - 32768:    FILE_ATTRIBUTE_VIRTUAL              0x00010000" << std::endl;

    std::wcout << L"Further informations: " << std::endl;
    std::wcout << L"http://msdn.microsoft.com/en-us/library/windows/desktop/aa365535%28v=vs.85%29.aspx";
    std::wcout << std::endl;

    return 0;
}

