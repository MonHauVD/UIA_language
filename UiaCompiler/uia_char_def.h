#ifndef CHAR_DEF_H
#define CHAR_DEF_H

// Phần 1: Số
#define A 0
#define I 1
#define U 2
#define a 3
#define u 4
#define i 5
#define Aa 6
#define Au 7
#define Ai 8
#define Ia 9

// Macro đặc biệt để chuyển đổi số
#define iiii(x) (x)

// Phần 2: Bảng chữ cái viết hoa
#define Aaa A
#define Aau B
#define Aai C
#define Aua D
#define Auu E
#define Aui F
#define Aia G
#define Aiu H
#define Aii I
#define Iaa J
#define Iau K
#define Iai L
#define Iua M
#define Iuu N
#define Iui O
#define Iia P
#define Iiu Q
#define Iii R
#define Uaa S
#define Uau T
#define Uai U
#define Uua V
#define Uuu W
#define Uui X
#define Uia Y
#define Uiu Z

// Phần 3: Bảng chữ cái viết thường
#define aaa a
#define aau b
#define aai c
#define aua d
#define auu e
#define aui f
#define aia g
#define aiu h
#define aii i
#define iaa j
#define iau k
#define iai l
#define iua m
#define iuu n
#define iui o
#define iia p
#define iiu q
#define iii r
#define uaa s
#define uau t
#define uai u
#define uua v
#define uuu w
#define uui x
#define uia y
#define uiu z

// Phần 4: Các ký tự đặc biệt
#define A_a ' '      // Dấu cách
#define A_u '\n'     // Xuống dòng
#define A_i '\t'     // Tab
#define A_A .      // Dấu chấm
#define A_I ,      // Dấu phẩy
#define A_U ;      // Dấu chấm phẩy
#define I_a :      // Dấu hai chấm
#define I_u(x) #x  // Dấu nháy kép
#define I_i \     // Dấu ngoặc đơn
#define I_A {      // Dấu ngoặc nhọn mở
#define I_I }      // Dấu ngoặc nhọn đóng
#define I_U (      // Dấu ngoặc tròn mở
#define U_a )      // Dấu ngoặc tròn đóng
#define U_u [      // Dấu ngoặc vuông mở
#define U_i ]      // Dấu ngoặc vuông đóng
#define U_A +      // Dấu cộng
#define U_I -      // Dấu trừ
#define U_U *      // Dấu nhân
#define a_a /      // Dấu chia
#define a_u =      // Dấu bằng
#define a_i <      // Dấu nhỏ hơn
#define a_A >      // Dấu lớn hơn
#define a_I !      // Dấu chấm than
#define a_U ?      // Dấu hỏi
#define u_a _      // Dấu gạch dưới
#define u_u #      // Dấu thăng
#define u_i $      // Dấu đô la
#define u_A %      // Dấu phần trăm
#define u_I &      // Dấu và
#define u_U |      // Dấu gạch đứng
#define i_a \     // Dấu gạch chéo ngược
#define i_u @      // Dấu @

// Phần 4.1: Các toán tử kép
#define Uiaa <=   // Nhỏ hơn hoặc bằng
#define Uiau >=   // Lớn hơn hoặc bằng
#define Uiai ==   // Bằng nhau
#define Uiua !=   // Không bằng
#define Uiuu ++   // Tăng 1
#define Uiui --   // Giảm 1
#define Uiia <<=  // Dịch trái và gán
#define Uiiu >>=  // Dịch phải và gán
#define Uiii +=   // Cộng và gán
#define Ui_a -=   // Trừ và gán
#define Ui_u *=   // Nhân và gán
#define Ui_i /=   // Chia và gán
#define Ui_A %=   // Chia lấy dư và gán
#define Ui_I &=   // AND và gán
#define Ui_U |=   // OR và gán
#define U_aa ^=   // XOR và gán
#define U_au <<   // Dịch trái
#define U_ai >>   // Dịch phải
#define U_ua &&   // AND logic
#define U_uu ||   // OR logic
#define U_ui ->   // Truy cập thành viên qua con trỏ
#define U_ia ::   // Toán tử phạm vi

// Phần 5: Các từ khóa C++ phổ biến
// #define aaaa #includes
#define Aaaa using
#define Aaau namespace
#define Aaai std
#define Aaua int
#define Aauu void
#define Aaui return
#define Aaia if
#define Aaiu else
#define Aaii for
#define Aa_a while
#define Aa_u do
#define Aa_i switch
#define Aa_A case
#define Aa_I break
#define Aa_U continue
#define Auaa class
#define Auau struct
#define Auai public
#define Auua private
#define Auuu protected
#define Auui const
#define Auia static
#define Auiu virtual
#define Auii override
#define Au_a final
#define Au_u template
#define Au_i typename
#define Au_A auto
#define Au_I nullptr
#define Au_U true
#define Aiaa false
#define Aiau new
#define Aiai delete
#define Aiua this
#define Aiuu sizeof
#define Aiui typeof
#define Aiia try
#define Aiiu catch
#define Aiii throw
#define Ai_a exception

// Phần 6: Các từ khóa C++ bổ sung
#define A_aa char
#define A_au double
#define A_ai float
#define A_ua long
#define A_uu short
#define A_ui unsigned
#define A_ia signed
#define A_iu bool
#define A_ii enum
#define A_Aa union
#define A_Au typedef
#define A_Ai extern
#define A_Ia inline
#define A_Iu explicit
#define A_Ii mutable
#define A_Ua volatile
#define A_Uu register
#define A_Ui friend
#define Iaaa operator
#define Iaau export

// Phần 7: Các function quan trọng
#define Iaua main
#define Iauu cout
#define Iaui cin
#define Iaia endl
#define Iaiu printf
#define Iaii scanf
#define Ia_a malloc
#define Ia_u free
#define Ia_i calloc
#define Ia_A realloc
#define Ia_I strlen
#define Ia_U strcpy
#define Iuaa strcat
#define Iuau strcmp
#define Iuai strstr
#define Iuua strtok
#define Iuuu memcpy
#define Iuui memmove
#define Iuia memset
#define Iuiu memcmp
#define Iuii atoi
#define Iu_a atof
#define Iu_u itoa
#define Iu_i rand
#define Iu_A srand
#define Iu_I time
#define Iu_U clock
#define Iiaa exit
#define Iiau abort
#define Iiai assert
#define Iiua fopen
#define Iiuu fclose
#define Iiui fread
#define Iiia fwrite
#define Iiiu fseek
#define Iiii ftell
#define Ii_a rewind
#define Ii_u remove
#define Ii_i rename
#define Ii_A tmpfile
#define Ii_I tmpnam
#define Ii_U setvbuf
#define I_aa fprintf
#define I_au fscanf
#define I_ai fgets
#define I_ua fputs
#define I_uu getc
#define I_ui putc
#define I_ia ungetc
#define I_iu fflush
#define I_ii feof
#define I_Aa ferror
#define I_Au clearerr
#define I_Ai perror
#define I_Ia strerror
#define I_Iu setlocale
#define I_Ii localeconv
#define I_Ua isalnum
#define I_Uu isalpha
#define I_Ui iscntrl
#define Uaaa isdigit
#define Uaau isgraph
#define Uaai islower
#define Uaua isprint
#define Uauu ispunct
#define Uaui isspace
#define Uaia isupper
#define Uaiu isxdigit
#define Uaii tolower
#define Ua_a toupper
#define Ua_u abs
#define Ua_i labs
#define Ua_A div
#define Ua_I ldiv
#define Ua_U rand
#define Uuaa srand
#define Uuau malloc
#define Uuai calloc
#define Uuua realloc
#define Uuuu free
#define Uuui abort
#define Uuia exit
#define Uuiu atexit
#define Uuii system
#define Uu_a getenv
#define Uu_u bsearch
#define Uu_i qsort

// Phần 8: Các ký tự còn lại trong bảng ASCII
#define Uu_A '~'    // ~
#define Uu_I '`' // `
#define Uu_U '^'    // ^

#endif // CHAR_DEF_H 