#include <iostream>
#include <GL/sgl.hpp>

// Types ------------------------------------------------ -

// The positions of squares on the game board
enum class Square {
    Northwest, North,  Northeast,
    West,      Center, East,
    Southwest, South,  Southeast,
    None
};

// Player marks
enum class Player {
    X, O, None
};

// Global variables --------------------------------------

Player nw, n, ne, w, c, e, sw, s, se;
Player current_player;
// keep track of what mark is in what square
// and who the current player is

// For example, you could have the variable named nw record the
// mark in the Square::Northwest square.  It initially would be
// Player::None when the game begins


// -------------------------------------------------------
void player_switch(){
	if (current_player == Player::X) {
		current_player = Player::O;
	}
	else {
		current_player = Player::X;
	}
}
void initialize() {
	nw = Player::None;
	n = Player::None;
	ne = Player::None;
	w = Player::None;
	c = Player::None;
	e = Player::None;
	sw = Player::None;
	s = Player::None;
	se = Player::None;
	current_player = Player::X;
}

Square point_to_square(double x, double y) {
	if (x < 100) {
		if (y < 100) {
			return Square::Southwest;
		}
		else if(y > 100 && y < 200) {
			return Square::West;
		}
		else if (y > 200 && y < 300) {
			return Square::Northwest;
		}
	}
	else if (x > 100 && x < 200) {
		if (y < 100) {
			return Square::South;
		}
		else if (y > 100 && y < 200) {
			return Square::Center;
		}
		else if (y > 200 && y < 300) {
			return Square::North;
		}
	}
	else if (x > 200 && x < 300) {
		if (y < 100) {
			return Square::Southeast;
		}
		else if (y > 100 && y < 200) {
			return Square::East;
		}
		else if (y > 200 && y < 300) {
			return Square::Northeast;
		}
	}


    //return Square::None;  // <-- this is a placeholder
}

void square_to_point(Square square, double& x, double& y) {
	if (square == Square::Southwest) {
		x = 50;
		y = 50;
	}
	else if (square == Square::South) {
		x = 150;
		y = 50;
	}
	else if (square == Square::Southeast) {
		x = 250;
		y = 50;
	}
	else if (square == Square::West) {
		x = 50;
		y = 150;
	}
	else if (square == Square::Center) {
		x = 150;
		y = 150;
	}
	else if (square == Square::East) {
		x = 250;
		y = 150;
	}
	else if (square == Square::Northwest) {
		x = 50;
		y = 250;
	}
	else if (square == Square::North) {
		x = 150;
		y = 250;
	}
	else if (square == Square::Northeast) {
		x = 250;
		y = 250;
	}
    // point at the center of that square
}


void draw_player(Player p, Square sq) {
	double x, y;
	square_to_point(sq, x, y);
	if (p == Player::X) {
		sgl::draw_line(x - 50, y + 50, x + 50, y - 50);
		sgl::draw_line(x + 50, y + 50, x - 50, y - 50);
		
	}
	else if (p == Player::O) {
		sgl::draw_circle(x, y, 50);
	}
	// Add your code to draw player p (X or O) centered within 
    // game square sq
}

void draw() {
	sgl::draw_line(100, 0, 100, 300);
	sgl::draw_line(200, 0, 200, 300);
	sgl::draw_line(0, 100, 300, 100);
	sgl::draw_line(0, 200, 300, 200);
	// Add your code to draw the game board and the player's
    // marks as appropriate
	draw_player(se, Square::Southeast);
	draw_player(s, Square::South);
	draw_player(sw, Square::Southwest);
	draw_player(e, Square::East);
	draw_player(c, Square::Center);
	draw_player(w, Square::West);
	draw_player(ne, Square::Northeast);
	draw_player(n, Square::North);
	draw_player(nw, Square::Northwest);
}

void mouse_pressed(double x, double y, sgl::MouseButton) {
	if (point_to_square(x,y) == Square::Southeast) {
		if (se == Player::None) {
			se = current_player;
			player_switch();
		}
	}
	if (point_to_square(x, y) == Square::South) {
		if (s == Player::None) {
			s = current_player;
			player_switch();
		}
	}
	if (point_to_square(x, y) == Square::Southwest) {
		if (sw == Player::None) {
			sw = current_player;
			player_switch();
		}
	}
	if (point_to_square(x, y) == Square::East) {
		if (e == Player::None) {
			e = current_player;
			player_switch();
		}
	}
	if (point_to_square(x, y) == Square::Center) {
		if (c == Player::None) {
			c = current_player;
			player_switch();
		}
	}
	if (point_to_square(x, y) == Square::West) {
		if (w == Player::None) {
			w = current_player;
			player_switch();
		}
	}
	if (point_to_square(x, y) == Square::Northeast) {
		if (ne == Player::None) {
			ne = current_player;
			player_switch();
		}
	}
	if (point_to_square(x, y) == Square::North) {
		if (n == Player::None) {
			n = current_player;
			player_switch();
		}
	}
	if (point_to_square(x, y) == Square::Northwest) {
		if (nw == Player::None) {
			nw = current_player;
			player_switch();
		}
	}
	// Add your code to respond to the players' mouse clicks
	
    std::cout << "x = " << x << ",  y = " << y << '\n';

    // Force the window to be redrawn
    sgl::update_window();
}

int main() {
    // Initialize the game board global variables
    initialize(); 
    // Create the window
    sgl::create_window("Tic-Tac-Toe", 0, 300, 0, 300);
    // Set the window painting function to your draw function
    sgl::set_paint_function(draw);
    // Set the mouse pressed function to your mouse pressed function
    sgl::set_mouse_pressed_function(mouse_pressed);
    // Start the graphical application
    sgl::run_window();
}
