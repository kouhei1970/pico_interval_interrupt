#include "pico/stdlib.h"

#define GPIO_NO   ( 0 )
#define LED_PIN (25)

bool callback(repeating_timer_t *rt)
{
    /* 割り込み毎にトグルする */
    if ( gpio_get( GPIO_NO ) != 0 )
    {
        gpio_put( GPIO_NO, 0 );
    }
    else
    {
        gpio_put( GPIO_NO, 1 );
    }

    unsigned short hoge=*(unsigned short*)(*rt).user_data;
    if (hoge==1){
        gpio_put( LED_PIN, 1 );
    }
    else{
        gpio_put( LED_PIN, 0 );
    }


    /* 500us待機 */
    busy_wait_us_32( 50 );

    return ( true );
}

void main( void )
{
    static repeating_timer_t timer;
    unsigned short hoge=1;


    /* GPIO設定 */
    gpio_init( GPIO_NO );
    gpio_set_dir( GPIO_NO, GPIO_OUT );
    gpio_init( LED_PIN );
    gpio_set_dir( LED_PIN, GPIO_OUT );



    /* インターバルタイマ設定 */
    add_repeating_timer_us( 200, &callback, &hoge, &timer );

    while( true )
    {
        hoge=1;
        //gpio_put( LED_PIN, 1 );
        sleep_ms(1000);
        hoge=0;
        //gpio_put( LED_PIN, 0 );
        sleep_ms(1000);

    }

}
