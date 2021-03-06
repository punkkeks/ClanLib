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

#include "../View/view.h"
#include "../../Display/Font/font.h"
#include "../../Display/2D/color.h"

namespace clan
{
	enum class TextAlignment
	{
		left,
		right,
		center,
		justify/*,
		start,
		end*/
	};

	enum class LineBreakMode
	{
		//word_wrapping,
		//char_wrapping,
		clipping,
		truncating_head,
		truncating_tail,
		truncating_middle
	};

	class TextStyle;
	class LabelViewImpl;

	class LabelView : public View
	{
	public:
		LabelView();

		std::string text() const;
		void set_text(const std::string &value);

		TextAlignment text_alignment() const;
		void set_text_alignment(TextAlignment alignment);

		const TextStyle &text_style() const;
		TextStyle &text_style();

		LineBreakMode line_break_mode() const;
		void set_line_break_mode(LineBreakMode value);

		void render_content(Canvas &canvas) override;
		float get_preferred_width(Canvas &canvas) override;
		float get_preferred_height(Canvas &canvas, float width) override;
		float get_first_baseline_offset(Canvas &canvas, float width) override;
		float get_last_baseline_offset(Canvas &canvas, float width) override;

	private:
		std::shared_ptr<LabelViewImpl> impl;
	};

}
