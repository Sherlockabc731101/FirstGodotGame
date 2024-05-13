#include "FirstGodotGame2D.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/input.hpp>

using namespace godot;

void FirstGodotGame2D::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("get_speed"), &FirstGodotGame2D::get_speed);
    ClassDB::bind_method(D_METHOD("set_speed", "speed"), &FirstGodotGame2D::set_speed);
    ClassDB::add_property("FirstGodotGame2D",PropertyInfo(Variant::FLOAT, "speed"), "set_speed", "get_speed");

    ClassDB::bind_method(D_METHOD("first_godot_game_2d", "words"), &FirstGodotGame2D::first_godot_game_2d);
    ADD_SIGNAL(MethodInfo("First_Godot_Game_2D_Signal", PropertyInfo(Variant::STRING, "data")));
}
FirstGodotGame2D::FirstGodotGame2D()
{
    if(Engine::get_singleton()->is_editor_hint())
    {
        set_process_mode(Node::ProcessMode::PROCESS_MODE_DISABLED);
    }
    UtilityFunctions::print("First Godot Game 2D!");
}

FirstGodotGame2D::~FirstGodotGame2D()
{
        
}

void FirstGodotGame2D::first_godot_game_2d(String words)
{
    UtilityFunctions::print("first godot game 2d! " + words);
    emit_signal("First_Godot_Game_2D_Signal", "data! ");
}

void FirstGodotGame2D::_process(double delta)
{
    UtilityFunctions::print("Hello from process!");
    velociity = Vector2(0.0f,0.0f);

    Input& inputSingleton = *Input::get_singleton();

    if(inputSingleton.is_action_pressed("d"))
    {
        velociity.x += 1.0f;
    }

    if(inputSingleton.is_action_pressed("a"))
    {
        velociity.x -= 1.0f;
    }

    if(inputSingleton.is_action_pressed("w"))
    {
        velociity.y -= 1.0f;
    }

    if(inputSingleton.is_action_pressed("s"))
    {
        velociity.y += 1.0f;
    }

    set_position(get_position() + (velociity * speed * delta));
}

void FirstGodotGame2D::set_speed(const double speed)
{
    this->speed = speed;
}

double FirstGodotGame2D::get_speed() const{
    return speed;
}