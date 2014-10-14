#!/usr/bin/env python3

import sfml as sf
from time import sleep

from collections import OrderedDict

import os

import shutil

SIZE_X = 800
SIZE_Y = 600
LEVEL_FILE="assets/levels/level%s.dat"
TILE_SIZE = 128
SCROLL_SIZE = 100
MAX_ZOOM=15
MAP_SIZE_X = 130
MAP_SIZE_Y = 9

SIZE_X_SCALE= int(SIZE_X * 0.75)
SIZE_Y_SCALE= int(SIZE_Y * 0.75)

DEFAULT_ZOOM = 3
START_LEVEL = "00"
LEVEL_INT = 0

w = sf.RenderWindow(sf.VideoMode(SIZE_X, SIZE_Y), "Magic Wizard level editor")

#default_view = w.defaultView;

view = sf.View()
view.reset(sf.Rectangle((0, 0), (SIZE_X_SCALE, SIZE_Y_SCALE)))
view.viewport = (0,0,0.75,0.75  )
view.move(0 , TILE_SIZE*2)



edit_rectangle = sf.RectangleShape((SIZE_X_SCALE, SIZE_Y_SCALE))
edit_rectangle.fill_color = sf.Color(255,0,0,200)

mouse_select = -1

hud_view = sf.View()
hud_view.reset(sf.Rectangle((0, 0), (SIZE_X, SIZE_Y)))
hud_view.viewport = (0.75,0,1,1)

hud_rectangle = sf.RectangleShape((SIZE_X - SIZE_X_SCALE, SIZE_Y))
hud_rectangle.fill_color = sf.Color(25,20,250,120)

hud2_view = sf.View()
hud2_view.reset(sf.Rectangle((0, 0), (SIZE_X, SIZE_Y)))
hud2_view.viewport = (0,0.75,1,1)

hud2_rectangle = sf.RectangleShape((SIZE_X*0.75, SIZE_Y))
hud2_rectangle.fill_color = sf.Color(25,250,250,120)


hud_selection_rectangle = sf.RectangleShape((20, 20))
hud_selection_rectangle.outline_color = sf.Color.RED
hud_selection_rectangle.fill_color = sf.Color(255,20,40,120)
hud_selection_rectangle.outline_thickness = 2

hud_selected_rectangle = sf.RectangleShape((20, 20))
hud_selected_rectangle.outline_color = sf.Color.YELLOW
hud_selected_rectangle.fill_color = sf.Color(255,250,140,120)
hud_selected_rectangle.outline_thickness = 2

#w.clear(sf.Color.BLUE)
#w.display()
w.view = view
#w.clear(sf.Color.GREEN)
#w.display()
w.title = "Magic Wizard Level Editor"
#w.display()
#w.capture().show()
view.zoom(DEFAULT_ZOOM)

current_draw = 'S'
current_index = 0


# declare and load a font
try: font = sf.Font.from_file("assets/fonts/TradeWinds-Regular.ttf")
except IOError: exit(1)

# create a text
text_level = sf.Text("Level")
text_level.font = font
text_level.character_size = 30
text_level.style = sf.Text.BOLD
text_level.color = sf.Color.RED


# draw it
#window.draw(text)

def get_level_string(level_int):
    return '%02d' % level_int

border_rectangle = sf.RectangleShape((MAP_SIZE_X*TILE_SIZE, MAP_SIZE_Y*TILE_SIZE))
border_rectangle.outline_color = sf.Color.RED
border_rectangle.fill_color = sf.Color(55,20,240,120)

mouse_rectangle = sf.RectangleShape((TILE_SIZE, TILE_SIZE))
mouse_rectangle.outline_color = sf.Color.RED
mouse_rectangle.fill_color = sf.Color(255,20,40,120)
mouse_rectangle.outline_thickness = 10

class TileManager(object):
    sprite_list = []
    hud_list = []
    sprite_count = 0
    available_letters = []

    def __init__(self, level="00"):

        self.zoom=0
        self.set_level(level)
        self.restart_all()        
        self.init_hud_list()
    def init_hud_list(self):

        distance = 2
        margin_left = 35
        scale = 0.25
        counter = 0
        lCounter = 0
        cCounter = 0
        for char in self.available_letters:
            if cCounter == 2 and counter > 8:
                cCounter = 0
                lCounter += 1
            if cCounter == 3:
                cCounter = 0
                lCounter += 1

            sprite = sf.Sprite(self.textures[char])
            position = sf.Vector2(TILE_SIZE*scale*cCounter, TILE_SIZE*scale*lCounter)
            position.x = (TILE_SIZE*scale*cCounter) + distance * (cCounter+1) + margin_left
            position.y = (TILE_SIZE*scale*lCounter) + distance * (lCounter+1) + margin_left



            if counter > 8:
                position.x += (TILE_SIZE*scale/2)



            print ("POSA",counter, cCounter, lCounter, position)
            sprite.scale((scale, scale))
            sprite.move(position)
            self.hud_list.append(sprite)
            cCounter += 1
            counter += 1
    def set_level(self, level="00"):
        self.filename = LEVEL_FILE % level

    def save_level(self):
        """ Saves level to disk """
        self.filename_copy = '%s.copy' % self.filename
        print(self.filename_copy)
        fd_write = open(self.filename_copy, 'w')
        for line in self.data:
            fd_write.write(line)
            fd_write.write('\n')

        fd_write.close()
        print("saved correctly")
        shutil.copy(self.filename_copy, self.filename)
        os.remove(self.filename_copy)



    def restart_all(self):
        self.init_variables()
        self.read_level()
        self.init_textures()
        self.init_tyles_types()
        #self.init_tyles_types()


    def init_variables(self):
        self.data = []
        self.textures = OrderedDict()
        self.init_sprite_list()

    def init_sprite_list(self):
        self.sprite_list = []    
        self.sprite_count = 0
        self.set_available()
    

    def init_textures(self):
        self.textures['Q'] = sf.Texture.from_file("assets/gfx/Grass/gras1.png")      
        self.textures['W'] = sf.Texture.from_file("assets/gfx/Grass/gras2.png")      
        self.textures['E'] = sf.Texture.from_file("assets/gfx/Grass/gras3.png")      
        self.textures['A'] = sf.Texture.from_file("assets/gfx/Grass/grass4.png")      
        self.textures['S'] = sf.Texture.from_file("assets/gfx/Grass/grass5.png")      
        self.textures['D'] = sf.Texture.from_file("assets/gfx/Grass/grass6.png")      
        self.textures['Z'] = sf.Texture.from_file("assets/gfx/Grass/grass7.png")      
        self.textures['X'] = sf.Texture.from_file("assets/gfx/Grass/grass8.png")      
        self.textures['C'] = sf.Texture.from_file("assets/gfx/Grass/grass9.png")           
        self.textures['R'] = sf.Texture.from_file("assets/gfx/Grass/grasscorner1.png")           
        self.textures['T'] = sf.Texture.from_file("assets/gfx/Grass/grasscorner2.png")           
        self.textures['F'] = sf.Texture.from_file("assets/gfx/Grass/grasscorner3.png")           
        self.textures['G'] = sf.Texture.from_file("assets/gfx/Grass/grasscorner4.png")           

        self.textures['!'] = sf.Texture.from_file("assets/gfx/back/exit.png")           
        self.textures['*'] = sf.Texture.from_file("assets/gfx/back/star.png")           
        self.textures['q'] = sf.Texture.from_file("assets/gfx/back/spear.png")           
        self.textures['w'] = sf.Texture.from_file("assets/gfx/skull.png")           
        self.set_available()

    def init_tyles_types(self):
        print("init_tyles_types", self.data, self.available_letters)
        self.init_sprite_list()
        sprites = []
        lCounter = 0 # Line Counter
        cCounter = 0 # Character Coutner
        for line in self.data:
            cCounter=0
            for char in line:
                if char in self.available_letters:
                    #print (lCounter, cCounter,(char))
                    sprite = sf.Sprite(self.textures[char])
                    position = sf.Vector2(TILE_SIZE*cCounter, TILE_SIZE*lCounter)
                    position.x = TILE_SIZE*cCounter 
                    position.y = TILE_SIZE*lCounter 
                    sprite.move(position)
                    #print(position) 
                    self.sprite_list.append(sprite)
                    sprites.append(sprite)
                    self.sprite_count += 1
                cCounter += 1
            #print (lCounter, cCounter, self.sprite_list, self.sprite_count)
            lCounter += 1
            #print (self.sprite_list, self.sprite_count)
        self.set_available()

    def set_available(self):
        self.available_letters = list(self.textures.keys())


    def read_level(self):
        print("READING LEVEL %s " % self.filename)
        try:
            self.data = [ x.rstrip('\n').rstrip('\r') for x in open(self.filename).readlines() ]
            self.valid_level()
        except FileNotFoundError:
            self.data = []
            for row in range(0, MAP_SIZE_Y):
                self.data.append(' ' * MAP_SIZE_X)

    def get_current_index(self, char):
        return self.available_letters.index(char)

    def get_tile_hud_coords(self, char_index):
        return self.hud_list[char_index].global_bounds



    def valid_level(self):
        #print(self.data)
        #print(self.filename)
        self.stats = []
        counter = 0
        for line in self.data:
            if len(line)<MAP_SIZE_X:
                line += ' ' * (MAP_SIZE_X-len(line))
                self.data[counter] = line
            self.stats.append({'size':len(line)})
            counter += 1
        print("MY, STATS", self.stats)

    def get_aim_sprite(self, current_draw):
        aim_sprite = sf.Sprite(self.textures[current_draw])
        #aim_sprite.outline_color = sf.Color.RED
        aim_sprite.color = sf.Color(255,20,40,220)
        #aim_sprite.outline_thickness = 10
        return aim_sprite



tile_manager = TileManager(START_LEVEL)
current_index = tile_manager.get_current_index(current_draw)


my_x = my_y = mposx = mposy = 0

def check_mouse(my_x, my_y, hud_rectangle):
    if hud_rectangle.global_bounds.contains((my_hud_x, my_hud_y)):
        return True
    else:
        return False


while w.is_open:
    mposition = sf.Mouse.get_position(w)

    # Counting coordinates of new sistem
    my_x = int(w.map_pixel_to_coords(mposition, view).x /TILE_SIZE)
    my_y = int(w.map_pixel_to_coords(mposition, view).y /TILE_SIZE)
    mposx = int(my_x) * TILE_SIZE
    mposy = int(my_y) * TILE_SIZE


    new_position = w.map_coords_to_pixel((mposx*TILE_SIZE, mposy*TILE_SIZE), view)
    new_position = (mposx, mposy)
    mouse_rectangle.position = new_position

    aim_sprite = tile_manager.get_aim_sprite(current_draw)
    aim_sprite.position = new_position


    for event in w.events:
        if type(event) is sf.KeyEvent and event.code is sf.Keyboard.ESCAPE:
            w.close()

        if type(event) is sf.KeyEvent and event.code is sf.Keyboard.S and event.released is True :
            tile_manager.save_level()
            

        if type(event) is sf.KeyEvent and event.code is sf.Keyboard.R_BRACKET and event.released is True :
            print(dir(event))
            LEVEL_INT += 1
            tile_manager.set_level(get_level_string(LEVEL_INT))
            tile_manager.restart_all()
            print(event.RELEASED, event.released)
            


        if type(event) is sf.KeyEvent and event.code is sf.Keyboard.L_BRACKET and event.released is True :
            print(dir(event))
            if LEVEL_INT>0:
                LEVEL_INT -= 1
                tile_manager.set_level(get_level_string(LEVEL_INT))
                tile_manager.restart_all()
                print(event.RELEASED, event.released)


        if type(event) is sf.KeyEvent and event.code is sf.Keyboard.DOWN  and event.released is True :
            tile_manager.set_available()
            chars = tile_manager.available_letters
            current_index = chars.index(current_draw)
            if current_index<len(chars)-1:
                current_index += 1
            else:
                current_index = 0
            current_draw = chars[current_index]

        if type(event) is sf.KeyEvent and event.code is sf.Keyboard.UP  and event.released is True :
            tile_manager.set_available()
            chars = tile_manager.available_letters
            current_index = chars.index(current_draw)

            if current_index>0:
                current_index -= 1
            else:
                current_index = len(chars)-1
            #print("CURRENT", current)
            current_draw = chars[current_index]

        if type(event) is sf.KeyEvent and event.code is sf.Keyboard.LEFT :
            view.move(-SCROLL_SIZE-(tile_manager.zoom*50),0)

        if type(event) is sf.KeyEvent and event.code is sf.Keyboard.RIGHT:
            view.move(SCROLL_SIZE+(tile_manager.zoom*50) , 0)

        if type(event) is sf.MouseWheelEvent:
            tile_manager.zoom + event.delta
            if event.delta > 0 and tile_manager.zoom<MAX_ZOOM:
                view.zoom(1.25)
                tile_manager.zoom += 1
            elif event.delta<0 and tile_manager.zoom>0:
                view.zoom(0.8)
                tile_manager.zoom -= 1
        if type(event) is sf.MouseButtonEvent and event.button is sf.Mouse.LEFT:
            if not check_mouse(my_x, my_y, hud_rectangle):
                if my_x < MAP_SIZE_X and my_y < MAP_SIZE_Y:
                    #print(tile_manager.data[my_y])
                    print(my_x, my_y)
                    new_line = list(tile_manager.data[my_y])
                    new_line[my_x] = current_draw
                    tile_manager.data[my_y] = ''.join(new_line)
                    tile_manager.init_tyles_types()
            else:
                print ("HERE IS A CHECK", mouse_select)
                current_index = mouse_select
                current_draw = tile_manager.available_letters[current_index]
        elif type(event) is sf.MouseButtonEvent and event.button is sf.Mouse.RIGHT and not check_mouse(my_x, my_y, hud_rectangle):
            if my_x < MAP_SIZE_X and my_y < MAP_SIZE_Y:
                print(tile_manager.data[my_y])
                print(my_x, my_y)
                new_line = list(tile_manager.data[my_y])
                new_line[my_x] = ' '
                tile_manager.data[my_y] = ''.join(new_line)
                tile_manager.init_tyles_types()
        
            


    w.view = view
    w.draw(edit_rectangle)

    w.draw(border_rectangle)
    for tile in tile_manager.sprite_list:
        w.draw(tile)

    if my_x < MAP_SIZE_X and my_y < MAP_SIZE_Y and my_x >= 0 and my_y >= 0:
        w.draw(aim_sprite)

    w.view = hud_view

    w.draw(hud_rectangle)

    my_hud_x = int(w.map_pixel_to_coords(mposition, hud_view).x )
    my_hud_y = int(w.map_pixel_to_coords(mposition, hud_view).y)

    tile_index = 0
    mouse_select = -1
    for tile in tile_manager.hud_list:
        w.draw(tile)
        if tile.global_bounds.contains((my_hud_x, my_hud_y)):
            selection = tile.global_bounds
            print ("hit", selection.left, selection.top)
            hud_selection_rectangle.position = (selection.left, selection.top)
            hud_selection_rectangle.size = (selection.width, selection.height)
            w.draw(hud_selection_rectangle)
            mouse_select = tile_index

        if tile_index == 1:
            print("local ", tile.global_bounds)

        tile_index += 1
    current_cords = tile_manager.get_tile_hud_coords(current_index)
    hud_selected_rectangle.position = (current_cords.left, current_cords.top)
    hud_selected_rectangle.size = (current_cords.width, current_cords.height)
    w.draw(hud_selected_rectangle)
    print (my_hud_x, my_hud_y)

    w.view = hud2_view
    w.draw(hud2_rectangle)
    text_level.string = "Level %s" % get_level_string(LEVEL_INT)
    w.draw(text_level)



    w.display()
    sleep(0.1)
    w.clear(sf.Color(180,180,250,120))

w.close()
exit()
