# File Attributes Tool

Tool to get and set attributes on files

Some special attributes of a file cannot be set directly via Windows Explorer.
For some other attributes it is very hard to set them using the Windows Explorer.

Using this command line tool you can set all the attributes to a file without any trouble.

### Usage

FileAttribTool.exe [get|set] [FileName] [AttribNum]

[AttribNum]:
- 1:        FILE_ATTRIBUTE_READONLY             0x00000001
- 2:        FILE_ATTRIBUTE_HIDDEN               0x00000002
- 4:        FILE_ATTRIBUTE_SYSTEM               0x00000004
- 16:       FILE_ATTRIBUTE_DIRECTORY            0x00000010
- 32:       FILE_ATTRIBUTE_ARCHIVE              0x00000020
- 64:       FILE_ATTRIBUTE_DEVICE               0x00000040
- 128:      FILE_ATTRIBUTE_NORMAL               0x00000080
- 256:      FILE_ATTRIBUTE_TEMPORARY            0x00000100
- 512:      FILE_ATTRIBUTE_SPARSE_FILE          0x00000200
- 1024:     FILE_ATTRIBUTE_REPARSE_POINT        0x00000400
- 2048:     FILE_ATTRIBUTE_COMPRESSED           0x00000800
- 4096:     FILE_ATTRIBUTE_OFFLINE              0x00001000
- 8192:     FILE_ATTRIBUTE_NOT_CONTENT_INDEXED  0x00002000
- 16384:    FILE_ATTRIBUTE_ENCRYPTED            0x00004000
- 32768:    FILE_ATTRIBUTE_VIRTUAL              0x00010000

Further informations:
http://msdn.microsoft.com/en-us/library/windows/desktop/aa365535%28v=vs.85%29.aspx

### Copyrights

Copyright 2016 David Roller

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.