/*
**  ClanLib SDK
**  Copyright (c) 1997-2015 The ClanLib Team
**
**  This software is provided 'as-is', without any express or implied
**  warranty.  In no event will the authors be held liable for any damages
**  arising from the use of this software.
**
**  Permission is granted to anyone to use this software for any purpose,
**  including commercial applications, and to alter it and redistribute it
**  freely, subject to the following restrictions:
**
**  1. The origin of this software must not be misrepresented; you must not
**     claim that you wrote the original software. If you use this software
**     in a product, an acknowledgment in the product documentation would be
**     appreciated but is not required.
**  2. Altered source versions must be plainly marked as such, and must not be
**     misrepresented as being the original software.
**  3. This notice may not be removed or altered from any source distribution.
**
**  Note: Some of the libraries ClanLib may link to may have additional
**  requirements or restrictions.
**
**  File Author(s):
**
**    Magnus Norddahl
*/

#pragma once

#include "API/Core/System/cl_platform.h"

namespace clan
{

class IODevice;

class ZipEndOfCentralDirectoryRecord
{
/// \name Construction
/// \{

public:
	ZipEndOfCentralDirectoryRecord();

	~ZipEndOfCentralDirectoryRecord();


/// \}
/// \name Attributes
/// \{

public:
	byte32 signature; // 0x06054b50

	byte16 number_of_this_disk;

	byte16 number_of_disk_with_start_of_central_directory;

	byte16 number_of_entries_on_this_disk;

	byte16 number_of_entries_in_central_directory;

	byte32 size_of_central_directory;

	byte32 offset_to_start_of_central_directory;

	byte16 file_comment_length;

	std::string file_comment;


/// \}
/// \name Operations
/// \{

public:
	void load(IODevice &input);

	void save(IODevice &output);


/// \}
/// \name Implementation
/// \{

private:
/// \}
};

}
