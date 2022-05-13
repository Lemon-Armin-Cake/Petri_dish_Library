import ctypes
PT_Library = ctypes.CDLL('./PD_Library.dll')

PT_Library.generate_medium.argtypes = [ctypes.c_float, ctypes.c_float, ctypes.c_int]
PT_Library.generate_medium.restype = ctypes.c_void_p
PT_Library.get_a.argtypes = [ctypes.c_void_p]
PT_Library.get_a.restype = ctypes.c_float
PT_Library.get_b.argtypes = [ctypes.c_void_p]
PT_Library.get_b.restype = ctypes.c_float
PT_Library.get_p.argtypes = [ctypes.c_void_p]
PT_Library.get_p.restype = ctypes.c_int
PT_Library.dispose_Growth_medium.argtypes = [ctypes.c_void_p]
PT_Library.dispose_Growth_medium.restype = None

G1 = PT_Library.generate_medium(20, 10, 36)
size_a = PT_Library.get_a(G1)
print ("a = ", size_a)
size_b = PT_Library.get_b(G1)
print ("b = ", size_b)
number_of_particles = PT_Library.get_p(G1)
print ("p = ", number_of_particles)

PT_Library.dispose_Growth_medium(G1)
