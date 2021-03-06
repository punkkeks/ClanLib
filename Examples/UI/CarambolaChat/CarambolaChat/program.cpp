
#include "precomp.h"
#include "program.h"
#include "Controllers/ChatWindow/chat_window_controller.h"

using namespace clan;

class DisplayResources : public DisplayCache
{
public:
	Resource<Sprite> get_sprite(Canvas &canvas, const std::string &id) override { throw Exception("No sprite resources"); }
	Resource<Texture> get_texture(GraphicContext &gc, const std::string &id) override { throw Exception("No texture resources"); }
	Resource<CollisionOutline> get_collision(const std::string &id) override { throw Exception("No collision resources"); }

	Resource<Image> get_image(Canvas &canvas, const std::string &id) override
	{
		if (loaded_images.find(id) == loaded_images.end())
		{
			loaded_images[id] = Image(canvas, PathHelp::combine(resource_path, id));
		}
		return loaded_images[id];
	}

	Resource<Font> get_font(Canvas &canvas, const FontDescription &desc)
	{
		std::string id = desc.get_unique_id();
		if (loaded_fonts.find(id) == loaded_fonts.end())
		{
			loaded_fonts[id] = Font(canvas, desc);
		}
		return loaded_fonts[id];
	}

private:
	std::string resource_path = "Resources";
	std::map<std::string, Resource<Font>> loaded_fonts;
	std::map<std::string, Resource<Image>> loaded_images;
};

int Program::main(const std::vector<std::string> &args)
{
	SetupCore setup_core;

	#ifndef _DEBUG
	std::string appdata_dir = clan::Directory::get_appdata("ClanLib", "Carambola", "1.0");
	CrashReporter crash_reporter(appdata_dir);

	DetectHang detect_hang;
	#endif

	SetupSound setup_sound;
	SetupDisplay setup_display;
	SetupGL setup_gl;
	SetupNetwork setup_network;

	ResourceManager resources;
	DisplayCache::set(resources, std::make_shared<DisplayResources>());

	UIThread ui_thread(resources);

	auto chat_window = std::make_shared<ChatWindowViewController>();

	bool exit = false;
	Slot exit_slot = chat_window->window_view()->sig_close().connect([&](CloseEvent &e) { exit = true; });
	while (!exit)
	{
		KeepAlive::process(250);
	}

	return 0;
}

Application app(&Program::main);
