import ctypes
from tkinter import Button, Entry, Label, Tk, StringVar, END, messagebox


# Prime nums
def fill_arr_prime_nums(size):
    lib = ctypes.CDLL('./lib/lib_worker.so')
    _fill_arr_prime_nums = lib.fill_arr_prime_nums
    _fill_arr_prime_nums.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int)
    _fill_arr_prime_nums.restype = None

    array_res = (ctypes.c_int * size)()

    _fill_arr_prime_nums(array_res, size)

    return list(array_res)


# Insert num after even nus
def add_after_even_nums(arr, num):
    lib = ctypes.CDLL('./lib/lib_worker.so')
    _add_after_even_nums = lib.add_after_even_nums
    _add_after_even_nums.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.POINTER(ctypes.c_int), ctypes.c_int, ctypes.c_int, ctypes.c_int)
    _add_after_even_nums.restype = ctypes.c_int

    len_src = len(arr)
    arr = (ctypes.c_int * len_src)(*arr)

    len_dst = 0
    dst = (ctypes.c_int * len_dst)()

    len_dst = _add_after_even_nums(arr, dst, len_src, len_dst, num)

    print("len = ", len_dst)

    dst = (ctypes.c_int * len_dst)(*dst)

    _add_after_even_nums(arr, dst, len_src, len_dst, num)

    return list(dst)


# For buttons funcs
def arr_of_prime_nums():
    size_str = input_prime_nums_win.get()

    try:
        size = int(size_str)

        if (size < 1):
            result_win.delete(0, END)
            messagebox.showerror("Создание массива простых чисел", "Количество простых чисел:\nЧисло не может быть меньше 1")
            return

        arr = fill_arr_prime_nums(size)

        arr_str = ' '.join(str(num) for num in arr)
        result_win.delete(0, END)
        result_win.insert(END, arr_str)
    except:
        result_win.delete(0, END)
        messagebox.showerror("Создание массива простых чисел", "Количество простых чисел:\nДолжно быть введено одно число")



def arr_with_insert_num():
    insert_num_str = input_num_for_even_win.get()

    try:
        insert_num = int(insert_num_str)
    except:
        result_win.delete(0, END)
        messagebox.showerror("Вставка числа после четных чисел", "Число для вставки:\nДолжно быть введено одно число")
        return
    
    arr_str = input_arr_for_even_win.get()

    try:
        arr = [int(num) for num in arr_str.split()]
    except:
        result_win.delete(0, END)
        messagebox.showerror("Вставка числа после четных чисел", "Массив для вставки:\nДолжны быть введены только числа")
        return

    new_arr = add_after_even_nums(arr, insert_num)

    arr_str = ' '.join(str(num) for num in new_arr)
    result_win.delete(0, END)
    result_win.insert(END, arr_str)



# Window
task = Tk()
task.title('C libs in Python (lab_12)')
task.geometry('900x700')

# Prime numbers
input_prime_nums_text = Label(text = 'Количество чисел для создания массива простых чисел', font = ('Arial Bold', 16))
input_prime_nums_text.place(x = 100, y = 50, width = 700, height = 30)

prime_nums = StringVar()
input_prime_nums_win = Entry(task, textvariable = prime_nums, font = ('Arial Bold', 16))
input_prime_nums_win.place(x = 85, y = 100, width = 700, height = 40)

prime_nums_button = Button(task, text = 'Создать массив простых чисел', font = ('Arial Bold', 12), command = lambda: arr_of_prime_nums())
prime_nums_button.place(x = 200, y = 150, width = 500, height = 30)


# Insert after even nums
input_arr_for_even_text = Label(text = 'Массив для задания вставки числа после четного', font = ('Arial Bold', 16))
input_arr_for_even_text.place(x = 100, y = 250, width = 700, height = 30)

arr_for_even = StringVar()
input_arr_for_even_win = Entry(task, textvariable = arr_for_even, font = ('Arial Bold', 16))
input_arr_for_even_win.place(x = 85, y = 300, width = 700, height = 40)


input_num_for_even_text = Label(text = 'Число вставки после четного', font = ('Arial Bold', 16))
input_num_for_even_text.place(x = 100, y = 350, width = 700, height = 30)

num_for_even = StringVar()
input_num_for_even_win = Entry(task, textvariable = num_for_even, font = ('Arial Bold', 16))
input_num_for_even_win.place(x = 85, y = 400, width = 700, height = 40)

after_even_insert_button = Button(task, text = 'Вставить в массив после четных чисел данное число', font = ('Arial Bold', 12), command = lambda: arr_with_insert_num())
after_even_insert_button.place(x = 200, y = 450, width = 500, height = 30)


# Result
result_text = Label(text = 'Результат', font = ('Arial Bold', 16))
result_text.place(x = 15, y = 600, width = 150, height = 40)
result_win = Entry(task, font = ('Arial Bold', 16))
result_win.place(x = 150, y = 600, width = 700, height = 40)

task.mainloop()