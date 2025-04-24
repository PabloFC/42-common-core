# Push Swap Resources

## Blogs
- [Push Swap: Efficient Positional Sorting Algorithm](https://web.archive.org/web/20220802162832/https://www.codequoi.com/en/push_swap-efficient-positional-sorting-algorithm/#sorting_algorithm_for_3_numbers)
- [Push Swap in Less Than 4200 Operations](https://medium.com/@ulysse.gerkens/push-swap-in-less-than-4200-operations-c292f034f6c0)
- [42 Cursus Guide: Push Swap](https://42-cursus.gitbook.io/guide/2-rank-02/push_swap)

## YouTube Videos
- [Radix Sort Explained by ChioCode](https://www.youtube.com/watch?v=W_euZjKoHkM&ab_channel=ChioCode)
- [Push Swap Explained by Oceano](https://www.youtube.com/watch?app=desktop&v=OaG81sDEpVk&ab_channel=Oceano)
- [Push Swap in Short Format](https://www.youtube.com/shorts/4hJAqspcubU)
- [Push Swap Visualization by John Park](https://www.youtube.com/watch?v=7KW59UO55TQ&ab_channel=JOHNPARK)


<!-- GESTION DEL PROYECTO -->

<!-- push_swap/
├── Makefile
├── includes/
│   └── push_swap.h
├── srcs/
│   ├── main.c
│   ├── operations/
│   │   ├── push.c
│   │   ├── rotate.c
│   │   ├── reverse_rotate.c
│   │   └── swap.c
│   ├── parsing/
│   │   └── parse_args.c
│   ├── sorting/
│   │   ├── small_sort.c
│   │   ├── radix_sort.c
│   │   └── sort_utils.c
│   └── utils/
│       ├── stack_utils.c
│       ├── error_handling.c
│       ├── utils.c
│       └── ft_printf.c
└── libft/ (opcional) -->

<!-- Orden de Implementación (Pasos Clave)
Estructuras Básicas:

Define t_stack_node en push_swap.h. Ok

Implementa stack_new() y stack_add_back() (en stack_utils.c).

Operaciones (en este orden):

push.c (pa, pb)

swap.c (sa, sb, ss)

rotate.c (ra, rb, rr)

reverse_rotate.c (rra, rrb, rrr)

Parsing:

ft_isdigit.c y ft_atol (en error_handling.c).

parse_args.c (valida números, crea stack A, verifica duplicados).

Utils Esenciales:

stack_size() y is_sorted() (en utils.c).

free_stack() (para manejo de memoria).

Algoritmos:

small_sort.c: Ordenar 2 y 3 elementos.

sort_four_five(): Mover mínimos a B y ordenar.

radix_sort.c: Usar índices y bits.

Main:

Conecta todo: parsing → chequeo → algoritmo correspondiente. -->