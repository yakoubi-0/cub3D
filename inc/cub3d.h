/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 08:30:09 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/09/06 01:22:23 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include "MLX42.h"

#define SCREEN_HEIGHT 720
#define SCREEN_WIDTH 1280
// --------
#define GRID_HEIGHT 32
#define GRID_WIDTH 32
#define COLUMNS 18
#define ROWS 10
#define MAP_HEIGHT (GRID_HEIGHT * ROWS)
#define MAP_WIDTH (GRID_WIDTH * COLUMNS)
// --------
#define PLAYER_HEIGHT 6
#define PLAYER_WIDTH 6
// --------
#define FOV_ANGLE (60.0)

typedef struct player_s
{
    float x;
    float y;
    int move_speed;
    float rotation_speed;
    float rotation_angle;
} player_t;

typedef struct data_s
{
    mlx_t *mlx;
    player_t player;
    mlx_image_t *minimap;
    mlx_image_t *game;
    char map_grid[ROWS][COLUMNS];
} data_t;

typedef struct vect_s
{
    float x;
    float y;
}   vect_t;

typedef struct hitRay_s
{
    float distance;
    int is_horizontal;
}   hitRay_t;


// ----------------- Function Prototypes --------------------

// Drawing
int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
int set_color(char position);

void draw_pixels_to_map(data_t *data);
void draw_player(data_t *data);
void draw_one_grid(data_t *data, int x, int y, int sq_color);
void draw_pixels_to_map(data_t *data);
void draw_map(data_t *data);
void draw_fov(data_t *data);

// hooks()
void ft_hooks(data_t *data);


// 3d
float cast_ray(data_t *data, float angle);
void draw_wall_column(data_t *data, vect_t v1, int columnHeight, hitRay_t ray);
void draw_3d_walls(data_t *data, hitRay_t ray, int ray_num);
void clear_screen(data_t *data);

