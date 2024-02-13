all:
	g++ -o program main.cpp -Iinclude -Llib -lraylib -lopengl32 -lgdi32 -lwinmm
