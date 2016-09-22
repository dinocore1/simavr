#include <stdlib.h>
#include <stdio.h>

#include "sim_avr.h"
#include "sim_time.h"

#include "rotory_encoder.h"

static const char* irq_names[3] = {
  [IRQ_ROTORY_ENCODER_A] = ">rotory.A",
  [IRQ_ROTORY_ENCODER_B] = ">rotory.B",
  [IRQ_ROTORY_ENCODER_BUTTON] = ">rotory.BUTTON"
};

static const uint8_t state_table[4] = {
  0x0,
  0x1,
  0x3,
  0x2
};

void
rotory_encoder_init(
    struct avr_t* avr,
    rotory_encoder_t* e)
{
  e->irq = avr_alloc_irq(&avr->irq_pool, 0, 3, irq_names);
  e->avr = avr;
  e->state = state_table[0];
}



#define CHANNEL_A_BIT(state) (state_table[state] & 0x2)
#define CHANNEL_B_BIT(state) (state_table[state] & 0x1)

/*

static uint8_t getChannelAState(uint8_t state) {
  return (state_table[state] >> 1) & 0x1;
}

static uint8_t getChannelBState(uint8_t state) {
  return (state_table[state] & 0x1);
}

static void updateBits(rotory_encoder_t* e, uint8_t oldState, uint8_t newState) {
  if(CHANNEL_A_BIT(oldState) != CHANNEL_A_BIT(newState)) {
    avr_rase_irq(e->irq + IRQ_ROTORY_ENCODER_A, getChannelAState(e->state));
  }

}
*/

void
rotory_encoder_turn_cw(
    rotory_encoder_t* e)
{
  //uint8_t oldState = e->state;
  //uint8_t newState = (e->state+1) % 4;

  e->state = (e->state+1) % 4;
  avr_raise_irq(e->irq, state_table[e->state]);
}

void
rotory_encoder_turn_ccw(
    rotory_encoder_t* e)
{
  //uint8_t oldState = e->state;
  //uint8_t newState = (e->state+1) % 4;

  e->state = (e->state-1) % 4;
  avr_raise_irq(e->irq, state_table[e->state]);
}
