NAME = fdf

CC = gcc

FDF = fdf.a

LIBFT = libft_fdf/libft.a

LIBFT_B = libft_bonus/libft.a

CMPL = cd libft_fdf && make && cd ..

CMPL_B = cd libft_bonus && make && cd ..

SRCS = checkmap.c\
		fdf.c\
		get_next_line.c\
		drawing.c\
		checkmap_util.c\
		fdf_util.c\
		fdf_util2.c

SRCSB = fdf_bonus.c\
		fdf_b_util.c\
		fdf_util_b2.c\
		fdf_util_b3.c\
		checkmap_b.c\
		checkmap_util_b.c\
		drawing_bonus.c\
		get_next_line.c

OBJS = $(subst  .c,.o, $(SRCS))

OBJSB = $(subst .c,.o, $(SRCSB))

NAME_B = fdf_b

FDF_B = fdf_b.a

all : $(NAME)

$(NAME) : $(LIBFT) $(FDF)
		$(CC) $(FDF) $(LIBFT) -lmlx -framework OpenGL -framework AppKit -o  $(NAME)
		
$(FDF) : $(OBJS)
	$(CC)  -Wall -Wextra -Werror -c  $(SRCS)
	ar -rc $(FDF) $(OBJS) 

$(LIBFT) :
		$(CMPL)

bonus : $(NAME_B)

$(NAME_B) : $(LIBFT_B) $(FDF_B) 
	$(CC)  $(LIBFT_B) $(OBJSB) -lmlx -framework OpenGL -framework AppKit -o $(NAME_B)

$(FDF_B) : $(OBJSB)
		$(CC) -Wall -Wextra -Werror -c $(SRCSB)
		ar -rc $(FDF_B) $(OBJSB)

$(LIBFT_B) :
		$(CMPL_B)

clean :
		rm -f *.o *.a
		cd libft_fdf && make fclean && cd ..
		cd libft_bonus && make fclean && cd ..

fclean : clean
		rm -f $(NAME) $(NAME_B)

re : fclean all