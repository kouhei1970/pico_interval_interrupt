#include "pico/stdlib.h"

#define GPIO_00   ( 0 )

bool timer_callback( repeating_timer_t *rt )
{
    /* 割り込み毎にトグルする */
    if ( gpio_get( GPIO_00 ) != 0 )
    {
        gpio_put( GPIO_00, 0 );
    }
    else
    {
        gpio_put( GPIO_00, 1 );
    }

    /* 500us待機 */
    busy_wait_us_32( 500 );

    return ( true );
}

void main( void )
{
    static repeating_timer_t timer;

    /* GPIO設定 */
    gpio_init( GPIO_00 );
    gpio_set_dir( GPIO_00, GPIO_OUT );

    /* インターバルタイマ設定 */
    add_repeating_timer_ms( -1, &timer_callback, NULL, &timer );

    while( true )
    {

    }

}
