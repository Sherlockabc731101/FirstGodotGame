#include "register_types.h"
#include "FirstGodotGame2D.h"

#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/godot.hpp>

using namespace godot;

void initalize_first_godot_game_2d(ModuleInitializationLevel p_level)
{
    if(p_level != MODULE_INITIALIZATION_LEVEL_SCENE)
    {
        return;
    }

    ClassDB::register_class<FirstGodotGame2D>();
}

void uninitalize_first_godot_game_2d(ModuleInitializationLevel p_level)
{
    if(p_level != MODULE_INITIALIZATION_LEVEL_SCENE)
    {
        return;
    }

}

extern "C"
{
    GDExtensionBool GDE_EXPORT first_godot_game_2d_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization)
    {
        godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

        init_obj.register_initializer(initalize_first_godot_game_2d);
        init_obj.register_terminator(uninitalize_first_godot_game_2d);
        init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

        return init_obj.init();
    }
}