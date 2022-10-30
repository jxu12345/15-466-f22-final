#pragma once
#include "Mode.hpp"
#include "Scene.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <vector>

#include <algorithm>

#include "data_path.hpp"
#include "gl_errors.hpp"
#include "load_save_png.hpp"
#include "ColorTextureProgram.hpp"


struct Sprite {
    // constructor and destructor
    Sprite(std::string path);
    ~Sprite();

    glm::uvec2 drawable_size;

    glm::uvec2 size;
    std::vector< glm::u8vec4 > data;
    void set_drawable_size(const glm::uvec2 &new_drawable_size);

    void draw(glm::vec2 center_pos, float scale);
    
    glm::mat4 world_to_clip;

    // Based on DrawLines.hpp
    struct Vertex {
		Vertex(glm::vec3 const &Position_, glm::u8vec4 const &Color_, glm::vec2 const &TexCoord_) : Position(Position_), Color(Color_), TexCoord(TexCoord_) { }
		glm::vec3 Position;
		glm::u8vec4 Color;
		glm::vec2 TexCoord;
	};

	// Based on DrawLiens.cpp
	GLuint vertex_buffer = 0;
	GLuint vertex_buffer_for_color_texture_program = 0;

    // Texture
    GLuint png_texture;
};

extern Load< ColorTextureProgram > color_texture_program;