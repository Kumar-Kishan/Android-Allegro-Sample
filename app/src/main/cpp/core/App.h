//
// Created by kumar on 6/22/2019.
//

#ifndef ANDROIDALLEGROSAMPLE_APP_H
#define ANDROIDALLEGROSAMPLE_APP_H

#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <vector>

class App {
    ALLEGRO_DISPLAY* mDisplay;
    ALLEGRO_EVENT_QUEUE* mEventQueue;
    ALLEGRO_TIMER* mTimer;
    bool redraw;
    int mWidth;
    int mHeight;
public:
    App(){
        al_init();
        al_init_primitives_addon();

        mDisplay = al_create_display(0,0);
        mWidth = al_get_display_height(mDisplay);
        mHeight = al_get_display_height(mDisplay);
        mEventQueue = al_create_event_queue();
        mTimer = al_create_timer(1/60.0);


        al_register_event_source(mEventQueue, al_get_display_event_source(mDisplay));
        al_register_event_source(mEventQueue, al_get_timer_event_source(mTimer));
        al_start_timer(mTimer);

        redraw = true;
    }

    void Start(){
        while (true){

            if(redraw && al_is_event_queue_empty(mEventQueue)){
                al_clear_to_color(al_map_rgb(0,0,0));
                al_flip_display();
            }


            ALLEGRO_EVENT event;
            al_wait_for_event(mEventQueue, &event);

            //Add Your Game Logic Here

        }
    }
};


#endif //ANDROIDALLEGROSAMPLE_APP_H
