#include<cstdlib>
#include<ctime>
#include<iostream>
#include<time.h>

//SEML

#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<SFML\Window.hpp>
#include<SFML\System.hpp>
#include <SFML/Graphics.hpp>


using namespace sf;

int main()
{



    int count = 0;
    RenderWindow window(VideoMode(800, 600), "Game!");
    window.setFramerateLimit(60);


    Vertex line[] = 
    {
         Vertex(Vector2f(0.f, 380.f)),
         Vertex(Vector2f(800.f, 380.f))
    };

                    //----------------//
                    //background image//
                    //---------------//



    int Home_bg_flag = 0;
    Clock home_bg_Timer;
    Texture home_bgtex;
    if (!home_bgtex.loadFromFile("Textures/demo4.jpg"))
    {
        std::cout << "Failed to load background texture!" << std::endl;

    }
    Sprite home_bg;
    home_bg.setTexture(home_bgtex);
    float xdir = window.getSize().x / home_bg.getGlobalBounds().width;
    float ydir = window.getSize().y / home_bg.getGlobalBounds().height;
    home_bg.setScale(Vector2f(xdir, ydir));

    int all_menu_flag = 0;





    int menu_page_flag = 0;
    Texture menu_bgtex;
    if (!menu_bgtex.loadFromFile("Textures/menu_bg.jpg"))
    {
        std::cout << "Failed to load background texture!" << std::endl;

    }
    Sprite menu_bg;
    menu_bg.setTexture(menu_bgtex);
    float menu_xdir = window.getSize().x / menu_bg.getGlobalBounds().width;
    float menu_ydir = window.getSize().y / menu_bg.getGlobalBounds().height;
    menu_bg.setScale(Vector2f(menu_xdir, menu_ydir));



    //game_bg_1//

    int game_bg_flag = 0;
    Texture game_bg1tex;
    game_bg1tex.loadFromFile("Textures/bg1.jpg");
    Sprite game_bg;
    game_bg.setTexture(game_bg1tex);
    float game_xdir = window.getSize().x / game_bg.getGlobalBounds().width;
    float game_ydir = window.getSize().y / game_bg.getGlobalBounds().height;
    game_bg.setScale(Vector2f(game_xdir, game_ydir));

    //game_bg_2//

    Texture game_bg2tex;
    game_bg2tex.loadFromFile("Textures/bg2.jpg");
    Sprite game_bg2;
    game_bg2.setTexture(game_bg2tex);
    float game_xdir2 = window.getSize().x / game_bg2.getGlobalBounds().width;
    float game_ydir2 = window.getSize().y / game_bg2.getGlobalBounds().height;
    game_bg2.setScale(Vector2f(game_xdir2, game_ydir2));





    int owner_page_flag = 0;
    Texture owner_bgtex;
    if (!owner_bgtex.loadFromFile("Textures/owner1.png"))
    {
        std::cout << "Failed to load background texture!" << std::endl;

    }
    Sprite owner_bg;
    owner_bg.setTexture(owner_bgtex);
    float owner_xdir = window.getSize().x / owner_bg.getGlobalBounds().width;
    float owner_ydir = window.getSize().y / owner_bg.getGlobalBounds().height;
    owner_bg.setScale(Vector2f(owner_xdir, owner_ydir));



    Texture instruction_bgtex;
    if (!instruction_bgtex.loadFromFile("Textures/instruction.png"))
    {
        std::cout << "Failed to load background texture!" << std::endl;

    }
    Sprite instruction_bg;
    instruction_bg.setTexture(instruction_bgtex);
    float instruction_xdir = window.getSize().x / instruction_bg.getGlobalBounds().width;
    float instruction_ydir = window.getSize().y / instruction_bg.getGlobalBounds().height;
    instruction_bg.setScale(Vector2f(instruction_xdir, instruction_ydir));






    Font font;
    font.loadFromFile("fonts/ARIALBD.TTF");
    Font font_comic;
    font_comic.loadFromFile("fonts/VerminVibesV-Zlg3.ttf");
    Font font_comic_2;
    font_comic_2.loadFromFile("fonts/FunnyKid.ttf");




    Text text, new_game, resume_game, leaderboard, contributers, owners,
        back, player_1_name, player_2_name, start, restart,character, instruction;


    int new_game_flag = 0;
    new_game.setFont(font_comic);
    new_game.setCharacterSize(20);
    new_game.setFillColor(Color::White);
    new_game.setString("New Game");
    new_game.setPosition(150.f, 200.f);



    int resume_game_flag = 0;
    resume_game.setFont(font_comic);
    resume_game.setCharacterSize(20);
    resume_game.setFillColor(Color::White);
    resume_game.setString("Resume Game");
    resume_game.setPosition(200.f, 250.f);


    int owners_flag = 0;
    owners.setFont(font_comic);
    owners.setCharacterSize(20);
    owners.setFillColor(Color::White);
    owners.setString("Developers");  
    owners.setPosition(250.f, 300.f);


    int leaderboard_flag = 0;
    leaderboard.setFont(font_comic);
    leaderboard.setCharacterSize(20);
    leaderboard.setFillColor(Color::White);
    leaderboard.setString("Leaderboard");
    leaderboard.setPosition(300.f, 350.f);

    int instruction_flag = 0;
    instruction.setFont(font_comic);
    instruction.setCharacterSize(20);
    instruction.setFillColor(Color::White);
    instruction.setString("Instruction");
    instruction.setPosition(350.f, 400.f);




    int character_flag = 0,player_1_char_flag = 0, player_2_char_flag = 0;
    character.setFont(font_comic);
    character.setCharacterSize(25);
    character.setFillColor(Color::White);
    character.setString("Choose  PlayGround");
    character.setPosition(230.f, 80.f);




    


    int back_flag = 0;
    back.setFont(font_comic);
    back.setCharacterSize(20);
    back.setFillColor(Color::White);
    back.setString("Back");
    back.setPosition(50.f, 550.f);

    int restart_flag = 0;
    restart.setFont(font_comic);
    restart.setCharacterSize(20);
    restart.setFillColor(Color::White);
    restart.setString("Restart");
    restart.setPosition(665.f, 550.f);




    //collision sound
    SoundBuffer collision_tex;
    collision_tex.loadFromFile("collision.mp3");
    Sound collision;
    collision.setBuffer(collision_tex);



    //home sound 
    SoundBuffer home_tex;
    home_tex.loadFromFile("home.mp3");
    Sound home_sound;
    home_sound.setBuffer(home_tex);
    home_sound.setVolume(15.f);


    //winner sound 
    SoundBuffer owner_sound_tex;
    owner_sound_tex.loadFromFile("winer_bg_sound.mp3");
    Sound owner_sound;
    owner_sound.setBuffer(owner_sound_tex);
    owner_sound.setVolume(13.f);









    /*--------------*/
    /*-...SPRITE...../
    /................/
    /... PLAYER 1 .../
    /................/
    /...............*/
    /*--------------*/




     //----------------------------//
    //-selection playground pics--//
   //----------------------------//


    Sprite player_ground_1;
    Texture player_ground_1_tex;
    player_ground_1_tex.loadFromFile("Textures/Asset 54.png");
    player_ground_1.setTexture(player_ground_1_tex);
    player_ground_1.setPosition(280.f, 150.f);

    Sprite player_ground_2;
    Texture player_ground_2_tex;
    player_ground_2_tex.loadFromFile("Textures/Asset 53.png");
    player_ground_2.setTexture(player_ground_2_tex);
    player_ground_2.setPosition(280.f, 350.f);




    int m = 0;
    float scal1 = 1.5f, scal2 = 1.5f;
    int  player_1_derection = 2;
    

    //player_1--RUNNING--Sprite//
    Clock player_1_timer_run;
    Sprite player_1_run;
    Texture player_1_run_tex;
    player_1_run.setTexture(player_1_run_tex);
    IntRect Currentframe_player_1_run = IntRect(0, 0, 200, 200);
    player_1_run.setTextureRect(Currentframe_player_1_run);
    player_1_run.setScale(scal1, scal2);
    player_1_run.setPosition(40, 195);


    //player_1--Jumping--Sprite//

    int jump_flag = 0;
    float velocity = 0.0f;
    float gravity = 0.5f;

    Clock player_1_timer_jump;
    Sprite player_1_jump;
    Texture player_1_jump_tex;
    player_1_jump.setTexture(player_1_jump_tex);
    IntRect Currentframe_player_1_jump = IntRect(0, 0, 200, 200);
    player_1_jump.setTextureRect(Currentframe_player_1_jump);
    player_1_jump.setPosition(player_1_run.getPosition());



    //player_1--ATTACK_1--Sprite//
    Clock Timer_attack_player_1;
    Sprite player_1_attack_1;
    Texture player_1_tex;
    player_1_attack_1.setTexture(player_1_tex);
    IntRect Currentframe_player_1_attack_1 = IntRect(0, 0, 200, 200);
    player_1_attack_1.setTextureRect(Currentframe_player_1_attack_1);
    player_1_attack_1.setPosition(player_1_run.getPosition());
    player_1_attack_1.setScale(player_1_run.getScale());



    //player_1--IDLE--Sprite//
    Clock player_1_timer_idle;
    Sprite player_1_idle;
    Texture player_1_idle_tex;
    player_1_idle.setTexture(player_1_idle_tex);
    IntRect Currentframe_player_1_idle = IntRect(0, 0, 200, 200);
    player_1_idle.setTextureRect(Currentframe_player_1_idle);
    player_1_idle.setPosition(player_1_run.getPosition());
    player_1_idle.setScale(player_1_run.getScale());


    //collision detector for player 1
    CircleShape collision_ditect_1;
    collision_ditect_1.setRadius(5.f);
    /*collision_ditect_1.setFillColor(sf::Color(255, 255, 255, 10));*/
    collision_ditect_1.setFillColor(Color::Transparent);
    collision_ditect_1.setPosition(player_1_attack_1.getPosition().x + 145.f, player_1_attack_1.getPosition().y + 105.f);







    /*--------------*/
    /*-...SPRITE...../
    /................/
    /... PLAYER 2 .../
    /................/
    /...............*/
    /*--------------*/




    int p2 = 0;
    float scal1_2 = -1.5f, scal2_2 = 1.5f;
    int player_2_derection = 2;


    //player_2--RUNNING--Sprite//

    Clock player_2_timer_run;
    Sprite player_2_run;
    Texture player_2_run_tex;
    player_2_run.setTexture(player_2_run_tex);
    IntRect Currentframe_player_2_run = IntRect(0, 0, 200.f, 200.f);
    player_2_run.setTextureRect(Currentframe_player_2_run);
    player_2_run.setScale(scal1_2, scal2_2);
    player_2_run.setPosition(700, 186);


    //player_2--Jumping--Sprite//

    int jump_flag_2 = 0;
    float velocity_2 = 0.0f;
    float gravity_2 = 0.5f;

    Clock player_2_timer_jump;
    Sprite player_2_jump;
    Texture player_2_jump_tex;
    player_2_jump.setTexture(player_2_jump_tex);
    IntRect Currentframe_player_2_jump = IntRect(0, 0, 200.f, 200.f);
    player_2_jump.setTextureRect(Currentframe_player_2_jump);
    player_2_jump.setPosition(player_2_run.getPosition());



    //player_2--ATTACK_1--Sprite//

    Clock Timer_attack_player_2;
    Sprite player_2_attack_1;
    Texture player_2_attack_tex;
    player_2_attack_1.setTexture(player_2_attack_tex);
    IntRect Currentframe_player_2_attack_1 = IntRect(0, 0, 200.f, 200.f);
    player_2_attack_1.setPosition(player_2_run.getPosition());
    player_2_attack_1.setTextureRect(Currentframe_player_2_attack_1);
    player_2_attack_1.setScale(player_2_run.getScale());


    //player_2--IDLE--Sprite//

    Clock player_2_timer_idle;
    Sprite player_2_idle;
    Texture player_2_idle_tex;
    player_2_idle.setTexture(player_2_idle_tex);
    IntRect Currentframe_player_2_idle = IntRect(0, 0, 200.f,200.f);
    player_2_idle.setTextureRect(Currentframe_player_2_idle);
    player_2_idle.setPosition(player_2_run.getPosition().x, player_2_run.getPosition().y);
    player_2_idle.setScale(player_2_run.getScale());


    //colission detector for player 2

    CircleShape collision_ditect_2;
    collision_ditect_2.setRadius(5.f);
    collision_ditect_2.setFillColor(Color::Transparent);
    collision_ditect_2.setPosition(player_2_attack_1.getPosition().x - 150.f, player_2_attack_1.getPosition().y + 110.f);




    // players hp counters


    float player_1_hp = 150.f, player_2_hp = 150.f;

    RectangleShape hp_1, hp_2, king_platform;

    hp_1.setFillColor(sf::Color(232, 37, 97));
    hp_1.setSize(Vector2f(player_1_hp, 20.f));
    hp_1.setPosition(20.f, 20.f);


    hp_2.setFillColor(Color::Red);
    hp_2.setSize(Vector2f(player_2_hp, 20.f));
    hp_2.setPosition(630.f, 20.f);




    //king who will declare the winner

    Clock Timer_king_idle;

    Sprite king_idle;
    Texture king_idle_tex;
    king_idle_tex.loadFromFile("Sprites1/King.png");
    king_idle.setTexture(king_idle_tex);
    IntRect Currentframe_king_idle = IntRect(0, 0, 250, 250);
    king_idle.setTextureRect(Currentframe_king_idle);
    king_idle.setScale(1.5f, 1.5f);
    //king_idle.setPosition(100.f, 100.f);


    king_platform.setFillColor(sf::Color(142, 22, 22));
    king_platform.setSize(Vector2f(50.f, 20.f));
    king_platform.setPosition(king_idle.getPosition().x + 150.f, king_idle.getPosition().y + 250);




    //--------------//
    // players name //
    //--------------//

    /*Player 1 name */

    player_1_name.setFont(font);
    player_1_name.setCharacterSize(13);
    player_1_name.setFillColor(Color::White);
    player_1_name.setString("[ Player 1 ]");

    /*Player 2 name */

    player_2_name.setFont(font);
    player_2_name.setCharacterSize(13);
    player_2_name.setFillColor(Color::White);
    player_2_name.setString("[ player 2 ]");



    Sprite winner_bg;
    Texture winner_bg_tex;
    winner_bg_tex.loadFromFile("Sprites1/commic_bg.png");
    winner_bg.setTexture(winner_bg_tex);
    winner_bg.setScale(.7f, .4f);



    Font win_font;
    win_font.loadFromFile("fonts/Fighting Spirit 2.otf");
    Text win;
    win.setFont(win_font);
    win.setCharacterSize(25);
    win.setFillColor(Color::Black);


    //game loop
    while (window.isOpen())


    {

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }


                                    //----------//
                                    //home page//
                                    //---------//
        
        if (home_bg_Timer.getElapsedTime().asSeconds() >= 6.0f && Home_bg_flag == 0)
        {
            home_sound.play();
            Home_bg_flag = 1;
            all_menu_flag = 1;
            menu_page_flag = 1;

        }

                                    //----------//
                                    //menu page//
                                    //---------//

        // new game button

        if (Mouse::isButtonPressed(Mouse::Left) && instruction_flag != 1 && owners_flag != 1 && Home_bg_flag != 0)
        {


            if (new_game.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))))
            {
                home_sound.stop();
                menu_page_flag = 0;
                //new_game_flag = 1;
                character_flag = 1;
                all_menu_flag = 0;

            }

        }


        // playground selection part 

        if (Mouse::isButtonPressed(Mouse::Left) && instruction_flag != 1 && owners_flag != 1 && Home_bg_flag != 0 && character_flag == 1)
        {


            if (player_ground_1.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))))

            {
                player_1_char_flag = 1;
                
            }
        }




        if (Mouse::isButtonPressed(Mouse::Left) && instruction_flag != 1 && owners_flag != 1 && Home_bg_flag != 0 && character_flag == 1)
        {


            if (player_ground_2.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))))

            {
                player_1_char_flag = 2;

            }
        }


        // developer button part


        if (Mouse::isButtonPressed(Mouse::Left) && new_game_flag != 1 && Home_bg_flag != 0)
        {
            if (owners.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))))
            {
                owner_sound.play();
                home_sound.stop();
                new_game_flag = 0;
                all_menu_flag = 0;
                menu_page_flag = 0;
                owners_flag = 1;
            }
        }
        if (Mouse::isButtonPressed(Mouse::Left) && new_game_flag != 1 && Home_bg_flag != 0)
        {
            if (instruction.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))))
            {
                home_sound.stop();
                new_game_flag = 0;
                all_menu_flag = 0;
                menu_page_flag = 0;
                owners_flag = 0;
                instruction_flag = 1;
            }
        }



        //////////////
        // back button
        /////////////

        if (Mouse::isButtonPressed(Mouse::Left)) {
            if (back.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))))
            {
                owner_sound.stop();
                home_sound.play();
                instruction_flag = 0;
                owners_flag = 0;
                menu_page_flag = 1;
                new_game_flag = 0;
                all_menu_flag = 1;
                character_flag = 0;


                //resetting the game elements

                player_1_run.setPosition(40, 195);
                player_2_run.setPosition(700, 186);
                player_1_hp = 150.f;
                player_2_hp = 150.f;
            }

        }

        //////////////
       // restart button
      /////////////

        if (Mouse::isButtonPressed(Mouse::Left)) {
            if (restart.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))))
            {
                
                home_bg_Timer.restart();
                Home_bg_flag = 0;
                owner_sound.stop();
                instruction_flag = 0;
                owners_flag = 0;
                menu_page_flag = 0;
                new_game_flag = 0;
                all_menu_flag = 0;
                character_flag = 0;


                //resetting the game elements

                player_1_run.setPosition(40, 195);
                player_2_run.setPosition(700, 186);
                player_1_hp = 150.f;
                player_2_hp = 150.f;
            }

        }
        //update


                          /*--------------*/
                          /*....UPDATE...../
                          /................/
                          /... PLAYER 1 .../
                          /................/
                          /...............*/
                          /*--------------*/



     //player 1 idle position update  ---------> m = 0

        if (m == 0)
        {
            if (player_1_timer_idle.getElapsedTime().asSeconds() >= 0.2f)
            {
                Currentframe_player_1_idle.left += 200;
                if (Currentframe_player_1_idle.left >= 1600.f)
                {
                    Currentframe_player_1_idle.left = 0;
                }
                player_1_timer_idle.restart();
                player_1_idle.setTextureRect(Currentframe_player_1_idle);
                player_1_idle.setScale(player_1_run.getScale());
            }
            player_1_idle.setOrigin(player_1_run.getOrigin());

        }





        //player--1 running [----RIGHT------] position update  ---------> m = 2 


        if (Keyboard::isKeyPressed(Keyboard::D) && player_1_hp > 0 && collision_ditect_1.getPosition().x <= window.getSize().x) {
            m = 2;
            player_1_run.move(5.f, 0);
            player_1_idle.move(5.f, 0);
            player_1_derection = 2;
            player_1_run.setScale(scal1, scal2);
            player_1_run.setOrigin(0.f, 0.f);
        }


        //player--2 running [----LEFT------] position update  ---------> m = 4



        if (Keyboard::isKeyPressed(Keyboard::A) && player_1_hp > 0 && collision_ditect_1.getPosition().x >= 0) {
            m = 4;
            player_1_run.move(-5.f, 0);
            player_1_idle.move(-5.f, 0);
            player_1_derection = 4;
            player_1_run.setScale(-scal1, scal2);
            player_1_run.setOrigin(player_1_run.getGlobalBounds().width / scal2, 0.f);
        }



        // player 1 run animation 

        if (m == 2 || m == 4)
        {
            if (player_1_timer_run.getElapsedTime().asSeconds() >= 0.01f)
            {
                Currentframe_player_1_run.left += 200;
                if (Currentframe_player_1_run.left >= 1600.f)
                {
                    Currentframe_player_1_run.left = 0;
                    m = 0;
                }
                player_1_timer_run.restart();
                
                player_1_run.setTextureRect(Currentframe_player_1_run);

            }
            
        }



        


        //player--1 jumping position update  ---------> m = 3



        if (Keyboard::isKeyPressed(Keyboard::W) && jump_flag == 0 && player_1_hp > 0)
        {
            m = 3;
            velocity = -15.0f;
            jump_flag = 1;

        }

        velocity += gravity;
        player_1_jump.move(0, velocity);




        if (m == 3)  // jump animation
        {

            if (player_1_timer_jump.getElapsedTime().asSeconds() >= .3f)
            {
                Currentframe_player_1_jump.left += 200;
                if (Currentframe_player_1_jump.left >= 800.f)
                {
                    Currentframe_player_1_jump.left = 0;
                    m = 0;
                }
                player_1_timer_jump.restart();

                player_1_jump.setTextureRect(Currentframe_player_1_jump);



            }
            player_1_jump.setScale(player_1_run.getScale());
            player_1_jump.setOrigin(player_1_run.getOrigin());
            collision_ditect_1.setPosition(player_1_jump.getPosition());
        }

        // // jump movement

        if (player_1_jump.getPosition().y >= player_1_run.getPosition().y)
        {
            velocity = 0.0f;
            player_1_jump.setPosition(player_1_run.getPosition());
            jump_flag = 0;


        }







        //[[player---1---]] --atacking_1--  m = 1   /// attack sound effect //

        if (Keyboard::isKeyPressed(Keyboard::E) && player_1_hp > 0)
        {
            m = 1;
            Timer_attack_player_1.restart();
            player_1_attack_1.setOrigin(player_1_run.getOrigin());
        }

        if (m == 1)
        {
            if (Timer_attack_player_1.getElapsedTime().asSeconds() >= 0.02f) {
                Currentframe_player_1_attack_1.left += 200;
                if (Currentframe_player_1_attack_1.left >= 1200.f)
                {
                    Currentframe_player_1_attack_1.left = 0;
                    m = 0;

                }

                Timer_attack_player_1.restart();
                player_1_attack_1.setTextureRect(Currentframe_player_1_attack_1);
            }
        }



                            /*--------------*/
                            /*....UPDATE...../
                            /................/
                            /... PLAYER 2 .../
                            /................/
                            /...............*/
                            /*--------------*/




//player 2 idle position update  ---------> p2 = 0

        if (p2 == 0)
        {
            if (player_2_timer_idle.getElapsedTime().asSeconds() >= 0.2f)
            {
                Currentframe_player_2_idle.left += 200.f;
                if (Currentframe_player_2_idle.left >= 800.f)
                {
                    Currentframe_player_2_idle.left = 0;
                }
                player_2_timer_idle.restart();
                player_2_idle.setTextureRect(Currentframe_player_2_idle);
                player_2_idle.setScale(player_2_run.getScale());
            }
            player_2_idle.setOrigin(player_2_run.getOrigin());

        }






        //player--2 running [----RIGHT------] position update  ---------> p2 = 2


        if (Keyboard::isKeyPressed(Keyboard::Right) && collision_ditect_2.getPosition().x <= window.getSize().x) {
            p2 = 2;
            player_2_run.move(5.f, 0);
            player_2_idle.move(5.f, 0);
            player_2_derection = 4;
            player_2_run.setScale(-scal1_2, scal2_2);
            player_2_run.setOrigin(player_2_run.getGlobalBounds().width / scal2_2, 0.f);
        }

        //player--2 running [----LEFT------] position update  ---------> p2 = 4



        if (Keyboard::isKeyPressed(Keyboard::Left) && collision_ditect_2.getPosition().x >= 0) {
            p2 = 4;
            player_2_run.move(-5.f, 0);
            player_2_idle.move(-5.f, 0);
            player_2_derection = 2;
            player_2_run.setScale(scal1_2, scal2_2);
            player_2_run.setOrigin(0.f, 0.f);
        }





        if (p2 == 2 || p2 == 4)
        {
            if (player_2_timer_run.getElapsedTime().asSeconds() >= 0.01)
            {
                Currentframe_player_2_run.left += 200.f;
                if (Currentframe_player_2_run.left >= 1600.f)
                {
                    Currentframe_player_2_run.left = 0;
                    p2 = 0;
                }
                player_2_timer_run.restart();

                player_2_run.setTextureRect(Currentframe_player_2_run);

            }
            
            

        }







        //player 2 jump part

        if (Keyboard::isKeyPressed(Keyboard::Up) && jump_flag_2 == 0)
        {
            p2 = 3;
            velocity_2 = -15.0f;
            jump_flag_2 = 1;

        }

        velocity_2 += gravity_2;
        player_2_jump.move(0, velocity_2);




        if (p2 == 3)  // jump animation
        {

            if (player_2_timer_jump.getElapsedTime().asSeconds() >= .3f)
            {
                Currentframe_player_2_jump.left += 200.f;
                if (Currentframe_player_2_jump.left >= 800.f)
                {
                    Currentframe_player_2_jump.left = 0;
                    p2 = 0;
                }
                player_2_timer_jump.restart();

                player_2_jump.setTextureRect(Currentframe_player_2_jump);



            }
            player_2_jump.setScale(player_2_run.getScale());
            player_2_jump.setOrigin(player_2_run.getOrigin());
            collision_ditect_2.setPosition(player_2_jump.getPosition());
        }

        // // jump movement

        if (player_2_jump.getPosition().y >= player_2_run.getPosition().y)
        {
            velocity_2 = 0.0f;
            player_2_jump.setPosition(player_2_run.getPosition());
            jump_flag_2 = 0;


        }







        //[[player---2---]] --atacking_1--  p2 = 1   /// attack sound effect //

        if (Keyboard::isKeyPressed(Keyboard::Down) && player_2_hp > 0)
        {
            p2 = 1;
            Timer_attack_player_2.restart();
            player_2_attack_1.setOrigin(player_2_run.getOrigin());
        }

        if (p2 == 1)
        {
            if (Timer_attack_player_2.getElapsedTime().asSeconds() >= 0.02f) {
                Currentframe_player_2_attack_1.left += 200.f;
                if (Currentframe_player_2_attack_1.left >= 800.f)
                {
                    Currentframe_player_2_attack_1.left = 0;
                    p2 = 0;

                }

                Timer_attack_player_2.restart();
                player_2_attack_1.setTextureRect(Currentframe_player_2_attack_1);
            }
        }


        //[-----collision_check----]


        if (collision_ditect_2.getGlobalBounds().intersects(player_1_idle.getGlobalBounds()) && m == 1 && (player_1_derection == player_2_derection))
        {
            if (player_2_hp > 0) {
                collision.play();
            }
            
            player_2_hp -= 0.5f;
        }

        if (collision_ditect_1.getGlobalBounds().intersects(player_2_idle.getGlobalBounds()) && p2 == 1 && (player_1_derection == player_2_derection))
        {
            if (player_1_hp > 0) {
                collision.play();
            }
            player_1_hp -= 0.5f;
        }














        /*--------------------------------------------*/
       //player 2 position origin scale updaiting part/
      /*--------------------------------------------*/





        //player_2 idle position, origin and scale updating 

        player_2_idle.setOrigin(player_2_run.getOrigin());
        player_2_idle.setPosition(player_2_run.getPosition().x, player_2_run.getPosition().y);
        player_2_idle.setScale(player_2_run.getScale());


        ////player_2 jumping  orgin and scale updating 

        player_2_jump.setOrigin(player_2_run.getOrigin());
        player_2_jump.setScale(player_2_run.getScale());


        ////player_2 attack position, origin and scale updating

        player_2_attack_1.setOrigin(player_2_run.getOrigin());
        player_2_attack_1.setScale(player_2_run.getScale());
        player_2_attack_1.setPosition(player_2_run.getPosition());






        /*--------------------------------------------*/
       //player 1 position origin scale updaiting part/
      /*--------------------------------------------*/







        //player_1 idle position, origin and scale updating 

        player_1_idle.setOrigin(player_1_run.getOrigin());
        player_1_idle.setPosition(player_1_run.getPosition());
        player_1_idle.setScale(player_1_run.getScale());


        //player_1 jumping  orgin and scale updating 

        player_1_jump.setOrigin(player_1_run.getOrigin());
        player_1_jump.setScale(player_1_run.getScale());


        //player_1 attack position, origin and scale updating

        player_1_attack_1.setOrigin(player_1_run.getOrigin());
        player_1_attack_1.setScale(player_1_run.getScale());
        player_1_attack_1.setPosition(player_1_run.getPosition());




        //player names positioning acording to the player movement



        if (m == 0 || m == 2 || m == 4)
        {
            player_1_name.setPosition(player_1_run.getPosition().x + 130.f, player_1_run.getPosition().y + 85.f);
        }
        else if (m == 3)
        {
            player_1_name.setPosition(player_1_jump.getPosition().x + 130.f, player_1_jump.getPosition().y + 85.f);
        }

        if (p2 == 0 || p2 == 2 || p2 == 4)
        {
            player_2_name.setPosition(player_2_run.getPosition().x - 170.f, player_2_run.getPosition().y + 95.f);
        }
        else if (p2 == 3)
        {
            player_2_name.setPosition(player_2_jump.getPosition().x - 170.f, player_2_jump.getPosition().y + 95.f);
        }



        // winner name set

        if (player_1_hp <= 0)
        {
            win.setString(" Winner Player 2");
            
        }
        else if (player_2_hp <= 0)
        {
            win.setString(" Winner Player 1");
           
        }


        win.setPosition(king_idle.getPosition().x + 250.f, king_idle.getPosition().y + 80.f);


        winner_bg.setPosition(king_idle.getPosition().x + 200.f, king_idle.getPosition().y + 30.f);








        /*-----Collision ditetor shape reposition----*/

        collision_ditect_1.setPosition(player_1_attack_1.getPosition().x + 145.f, player_1_attack_1.getPosition().y + 105.f);
        collision_ditect_2.setPosition(player_2_attack_1.getPosition().x - 150.f, player_2_attack_1.getPosition().y + 110.f);


        /*-----Health Update------*/
        hp_1.setSize(Vector2f(player_1_hp, 20.f));
        hp_2.setSize(Vector2f(player_2_hp, 20.f));


                                /*---------------------------*/
                               /*....Winner declaretion....../
                              /............................./
                             /..............KING.........../
                            /............................./
                           /............................*/
                          /*---------------------------*/



        if (player_1_hp <= 0 || player_2_hp <= 0)
        {
            if (Timer_king_idle.getElapsedTime().asSeconds() >= 0.2f)
            {
                Currentframe_king_idle.left += 250;
                if (Currentframe_king_idle.left >= 2000)
                {
                    Currentframe_king_idle.left = 0;
                }
                Timer_king_idle.restart();
                king_idle.setTextureRect(Currentframe_king_idle);

            }

        }


                         //------------------//
                        // playground choose//
                       //------------------// 

        if (player_1_char_flag == 1)
        {
            player_1_run_tex.loadFromFile("Sprites1/run.png");
            player_1_idle_tex.loadFromFile("Sprites1/idle.png");
            player_1_tex.loadFromFile("Sprites1/Attack.png");
            player_1_jump_tex.loadFromFile("Sprites1/jump.png");


            player_2_run_tex.loadFromFile("Sprites2/run.png");
            player_2_jump_tex.loadFromFile("Sprites2/jump.png");
            player_2_attack_tex.loadFromFile("Sprites2/attack.png");
            player_2_idle_tex.loadFromFile("Sprites2/idle.png");


            game_bg_flag = 1;
            player_1_char_flag = 0;
            character_flag = 0;
            new_game_flag = 1;

        }
        else if (player_1_char_flag == 2)
        {
            player_1_run_tex.loadFromFile("Sprites3/run.png");
            player_1_idle_tex.loadFromFile("Sprites3/idle.png");
            player_1_tex.loadFromFile("Sprites3/Attack.png");
            player_1_jump_tex.loadFromFile("Sprites3/jump.png");


            player_2_run_tex.loadFromFile("Sprites4/run.png");
            player_2_jump_tex.loadFromFile("Sprites4/jump.png");
            player_2_attack_tex.loadFromFile("Sprites4/attack.png");
            player_2_idle_tex.loadFromFile("Sprites4/idle.png");

            game_bg_flag = 2;
            player_1_char_flag = 0;
            character_flag = 0;
            new_game_flag = 1;
        }
        
        




        window.clear();


        //draw everything


        if (Home_bg_flag == 0)
        {
            window.draw(home_bg);
        }
        else if (menu_page_flag == 1 || character_flag == 1)
        {
            window.draw(menu_bg);
            window.draw(restart);
        }
        else if (new_game_flag == 1)
        {
            if (game_bg_flag == 1)
            {
                window.draw(game_bg);
            }
            else if (game_bg_flag == 2)
            {
                window.draw(game_bg2);
            }
            
            window.draw(back);
            window.draw(restart);
        }
        else if (owners_flag == 1)
        {

            window.draw(owner_bg);
            window.draw(back);
            window.draw(restart);
        }
        else if (instruction_flag == 1)
        {

            window.draw(instruction_bg);
            window.draw(back);
            window.draw(restart);
        }

        



        if (new_game_flag == 1) {

            /*-----------------*/
           //player 1 draw part/
          /*-----------------*/
            if (player_1_hp > 0) {


                window.draw(hp_1);
                window.draw(player_1_name);
                if (m == 0)
                {
                    window.draw(player_1_idle);
                }
                else if (m == 1)
                {
                    window.draw(collision_ditect_2);
                    window.draw(player_1_attack_1);
                }
                else if ((m == 2 || m == 4))
                {
                    window.draw(player_1_run);
                }
                else if (m == 3)
                {
                    window.draw(player_1_jump);
                }
            }


            /*-----------------*/
           //player 2 draw part/
          /*-----------------*/

            if (player_2_hp > 0) {
                window.draw(hp_2);
                window.draw(player_2_name);
                if (p2 == 0)
                {
                    window.draw(player_2_idle);
                }

                else if (p2 == 1)
                {
                    window.draw(player_2_attack_1);
                    window.draw(collision_ditect_1);
                }

                else if ((p2 == 2 || p2 == 4))
                {
                    window.draw(player_2_run);
                }
                else if (p2 == 3)
                {
                    window.draw(player_2_jump);
                }
            }


            if (player_1_hp <= 0 || player_2_hp <= 0)
            {
                window.draw(winner_bg);
                window.draw(king_idle);
                window.draw(king_platform);
            }
            if (player_2_hp <= 0 || player_1_hp <= 0)
            {
                
                window.draw(win);
            }



            window.draw(line, 2, Lines);

        }

        if (all_menu_flag == 1)
        {
            window.draw(instruction);
            window.draw(new_game);
            window.draw(resume_game);
            window.draw(owners);
            window.draw(leaderboard);
            
        }
        if (character_flag == 1)
        {
            window.draw(back);
            window.draw(player_ground_1);
            window.draw(player_ground_2);
            window.draw(character);
        }







        window.display();
    }


    return 0;
}