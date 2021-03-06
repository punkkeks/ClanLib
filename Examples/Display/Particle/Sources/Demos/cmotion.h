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
**    Mark Page
*/

#pragma once

#include "../LinearParticle/L_ParticleSystem.h"

class DemoCMotion
{
public:
	DemoCMotion();

	int run(clan::DisplayWindow &window);

private:
	void set_style(clan::Canvas &canvas);
	void on_key_up(const clan::InputEvent& key, clan::Canvas canvas);
	void on_window_close();
	void run_a_step(int time);

private:
	bool quit;
	bool show_menu;
	bool random_ini_rotation;
	char current_style;
	clan::Colorf bg_color;

	L_MotionController motion_ctrl;
	L_Particle *particle;
	L_ShootingEffect* effect;
	clan::Font* font;
	clan::Colorf fontColor;
	L_BlendingMode blendingMode; 
};
