#ifndef FIRSTGODOTGAME2D_H
#define FIRSTGODOTGAME2D_H

#include <godot_cpp/classes/node2d.hpp>

namespace godot
{
    class FirstGodotGame2D : public Node2D
    {
        GDCLASS(FirstGodotGame2D, Node2D)
        
        private:
            double speed;
            Vector2 velociity;

        protected:
            static void _bind_methods();

        public:
        FirstGodotGame2D();//constructor
        ~FirstGodotGame2D();//destructor
        void first_godot_game_2d(String words);
        void set_speed(const double speed);
        double get_speed() const;
        void _process(double delta);
    };
}

#endif