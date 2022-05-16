/*
** EPITECH PROJECT, 2019
** font
** File description:
** rpg
*/

#include <stdlib.h>
#include "lib.h"
#include "model.h"
#include "window.h"
#include "my_rpg.h"
#include "player.h"

const int IMP_NBR = 5;

void print_text_improve(my_rpg_t *rpg, game_t *game)
{
    for (int i = 0; i < IMP_NBR; i++) {
        sfRenderWindow_drawText(game->win->window,
        rpg->imp_texts->text[i]->text, NULL);
    }
}

void set_text_imp(my_rpg_t *rpg, text_t *text, int nb)
{
    char *str = "Price: ";
    sfVector2f txt_pos = rpg->improve[nb + 3]->vector->set_position;

    txt_pos.x -= 200;
    txt_pos.y += 110;
    str = my_strcat(str, my_itoa(rpg->price[nb]));
    str = my_strcat(str, "\nNb of Improvement left: ");
    str = my_strcat(str, my_itoa(5 - rpg->stats_imp[nb]));
    sfText_setScale(text->text, (sfVector2f) {0.7, 0.7});
    sfText_setString(text->text, str);
    sfText_setPosition(text->text, txt_pos);
    sfText_setColor(text->text, sfBlack);
}

void reset_text_imp(my_rpg_t *rpg)
{
    for (int i = 0; i < IMP_NBR; i++) {
        set_text_imp(rpg, rpg->imp_texts->text[i], i);
    }
}

texts_t *text_improve(my_rpg_t *rpg)
{
    texts_t *texts = malloc(sizeof(texts_t));

    if (!texts)
        return NULL;
    texts->text = malloc(sizeof(text_t *) * IMP_NBR);
    if (!texts->text)
        return NULL;
    texts->font =
    sfFont_createFromFile("resources/font/pieces_of_eight/Pieces of Eight.ttf");
    if (texts->font == NULL)
        return NULL;
    for (int i = 0; i < IMP_NBR; i++) {
        texts->text[i] = malloc(sizeof(text_t));
        if (!texts->text[i])
            return (NULL);
        texts->text[i]->text = sfText_create();
        if (!texts->text[i]->text)
            return (NULL);
        sfText_setFont(texts->text[i]->text, texts->font);
        set_text_imp(rpg, texts->text[i], i);
    }
    return (texts);
}

texts_t *text_gold(void)
{
    texts_t *texts = malloc(sizeof(texts_t));

    if (!texts)
        return NULL;
    texts->text = malloc(sizeof(text_t *));
    if (!texts->text)
        return NULL;
    texts->font =
    sfFont_createFromFile("resources/font/pieces_of_eight/Pieces of Eight.ttf");
    if (texts->font == NULL)
        return NULL;
    texts->text[0] = malloc(sizeof(text_t));
    if (!texts->text[0])
        return (NULL);
    texts->text[0]->text = sfText_create();
        if (!texts->text[0]->text)
            return (NULL);
        sfText_setFont(texts->text[0]->text, texts->font);
    return (texts);
}