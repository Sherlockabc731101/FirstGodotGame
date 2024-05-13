extends Node2D


# Called when the node enters the scene tree for the first time.
func _ready():
	$FirstGodotGame2D.first_godot_game_2d("this is a test string!!")
	pass # Replace with function body.


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass


func _on_first_godot_game_2d_first_godot_game_2d_signal(data):
	print("data from signal is: " + data)
	pass # Replace with function body.
