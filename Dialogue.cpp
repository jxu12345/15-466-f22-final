#include "Dialogue.hpp"

Dialogue::Dialogue() {
    dialogue_box = new Sprite("images/dialogue_box.png");
}

Dialogue::~Dialogue() {

}

void Dialogue::set_dialogue(std::string main_text, std::vector<std::string> choices_text, bool are_color_options) {
    this->dialogue = main_text;
    this->choices = choices_text;
    this->color_options = are_color_options;
}

void Dialogue::draw_dialogue_box(glm::uvec2 const &window_size) {
    // Render the box where text goes
    dialogue_box->set_drawable_size(window_size);
    dialogue_box->draw(glm::vec2(400, 100), 0.25);

    // Render text
    dialogue_text_renderer->set_drawable_size(window_size);
	choices_renderer->set_drawable_size(window_size);
    dialogue_text_renderer->renderWrappedText(dialogue, 10.0f, dialogue_text_size, dialogue_text_color);

    if (color_options) {
        if (choices.size() != 2) {
            std::cout << "Invalid amount of choices: " << choices.size() << std::endl;
        }
        else {
            std::string choice1("> ");
            choice1.append(choices[0]);
            std::string choice2("> ");
            choice2.append(choices[1]);
            choices_renderer->renderLine(choice1, 0, 0, choices_text_size, choices_text_color1);
            choices_renderer->renderLine(choice2, 0, 60, choices_text_size, choices_text_color2);
        }
    }
    else {
        std::string choices_text;
        for (unsigned int i = 0; i < choices_text.size(); i++) {
            choices_text.append("> ");
            choices_text.append(choices[i]);
            choices_text.append("\n");
        }
        choices_renderer->renderWrappedText(choices_text, ((window_size.y / 4.0f) * 3.0f), choices_text_size, choices_text_color);
    }
}
