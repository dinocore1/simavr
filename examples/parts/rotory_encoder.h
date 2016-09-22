#ifndef __ROTORY_ENCODER_H__
#define __ROTORY_ENCODER_H__

#include "sim_irq.h"

enum {
  IRQ_ROTORY_ENCODER_A = 0,
  IRQ_ROTORY_ENCODER_B,
  IRQ_ROTORY_ENCODER_BUTTON,
};

typedef struct rotory_encoder_t {
  avr_irq_t * irq;
  struct avr_t * avr;
  uint8_t state;
} rotory_encoder_t;

void rotory_encoder_init(struct avr_t* avr, rotory_encoder_t* e);
void rotory_encoder_turn_cw(rotory_encoder_t* e);
void rotory_encoder_turn_ccw(rotory_encoder_t* e);
void rotory_encoder_click_button(rotory_encoder_t* e);

#endif // __ROTORY_ENCODER_H__
