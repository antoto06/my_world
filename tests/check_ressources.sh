#!/bin/bash

_def_map=../ressources/default/default_map3D.legend
_elem_bench1=../ressources/elements/bench_1.png
_house_1=../ressources/elements/house_1.png
_house_2=../ressources/elements/house_2.png
_object1=../ressources/elements/object1.png
_tree_1=../ressources/elements/tree_1.png
_font=../ressources/font/font01.png
_sound_back=../ressources/sound/background.ogg
_sound_build=../ressources/sound/build.ogg
_sound_dug=../ressources/sound/dug.ogg

echo -ne "**************** CHECKING DEFAULT ASSETS ****************\n\n"

if [ -f "$_def_map" ]; then
    echo -ne "default_map3D "
    echo -e "\e[92m[ OK ]\e[37m"
fi

echo -ne "**************** CHECKING ELEMENTS ASSETS ****************\n\n"

if [ -f "$_elem_bench1" ]; then
    echo -ne "element benc_1.png "
    echo -e "\e[92m[ OK ]\e[37m"
fi

if [ -f "$_house_1" ]; then
    echo -ne "element house_1.png "
    echo -e "\e[92m[ OK ]\e[37m"
fi

if [ -f "$_house_2" ]; then
    echo -ne "element house_2.png "
    echo -e "\e[92m[ OK ]\e[37m"
fi

if [ -f "$_object1" ]; then
    echo -ne "element object1.png "
    echo -e "\e[92m[ OK ]\e[37m"
fi

if [ -f "$_tree_1" ]; then
    echo -ne "element tree_1.png "
    echo -e "\e[92m[ OK ]\e[37m"
fi

echo -ne "**************** CHECKING FONT ASSETS ****************\n\n"

if [ -f "$_font" ]; then
    echo -ne "font font01.otf "
    echo -e "\e[92m[ OK ]\e[37m"
fi

echo -ne "**************** CHECKING SOUNDS ASSETS ****************\n\n"

if [ -f "$_sound_back" ]; then
    echo -ne "sound sound_back.ogg "
    echo -e "\e[92m[ OK ]\e[37m"
fi

if [ -f "$_sound_build" ]; then
    echo -ne "sound sound_build.ogg "
    echo -e "\e[92m[ OK ]\e[37m"
fi

if [ -f "$_sound_dug" ]; then
    echo -ne "sound sound_dug.ogg "
    echo -e "\e[92m[ OK ]\e[37m"
fi

echo -ne "**************** CHECKING TEXTURES ASSETS ****************\n\n"

echo -ne "Recuperation..\n"

ui[0]='../ressources/ui/background.jpg'
ui[1]='../ressources/ui/brown.png'
ui[2]='../ressources/ui/button_brown.png'
ui[3]='../ressources/ui/button_green_burn.png'
ui[4]='../ressources/ui/button_green_hover.png'
ui[5]='../ressources/ui/button_green.png'
ui[6]='../ressources/ui/convex_txtr_base.png'
ui[7]='../ressources/ui/gele_texture.jpg'
ui[7]='../ressources/ui/grass_texture_hover.jpg'
ui[8]='../ressources/ui/grass_texture.jpg'
ui[9]='../ressources/ui/hover_vertex.png'
ui[10]='../ressources/ui/panel_save.png'
ui[11]='../ressources/ui/rock_texture_burn.png'
ui[12]='../ressources/ui/rock_texture.jpg'
ui[13]='../ressources/ui/water.png'
ui[14]='../ressources/ui/water_texture.jpg'

for i in "${ui[@]}"
do
    if [ -f "$i" ];then
	echo -ne "texture $i "
	echo -e "\e[92m[ OK ]\e[37m"
    fi
done

