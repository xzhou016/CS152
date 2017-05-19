/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "mini_l.y"

	#include<stdio.h>
	#include<string.h>
	void yyerr(int, char *);
	extern int lineNum;
	extern int colNum;
	FILE *yyin;

/* Line 371 of yacc.c  */
#line 77 "y.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUMBER = 258,
     ID = 259,
     L_PARENT = 260,
     R_PARENT = 261,
     L_BRAC = 262,
     R_BRAC = 263,
     SUB = 264,
     SEMICOLON = 265,
     COLON = 266,
     COMMA = 267,
     TIMES = 268,
     DIV = 269,
     MOD = 270,
     ADD = 271,
     LT = 272,
     LTE = 273,
     GT = 274,
     GTE = 275,
     EQ = 276,
     NEQ = 277,
     NOT = 278,
     AND = 279,
     OR = 280,
     ASSIGN = 281,
     FUNCTION = 282,
     BEGIN_PARAMS = 283,
     END_PARAMS = 284,
     BEGIN_LOCALS = 285,
     END_LOCALS = 286,
     BEGIN_BODY = 287,
     END_BODY = 288,
     INTERGER = 289,
     ARRAY = 290,
     OF = 291,
     IF = 292,
     THEN = 293,
     ENDIF = 294,
     ELSE = 295,
     TRUE = 296,
     FALSE = 297,
     WHILE = 298,
     DO = 299,
     BEGINLOOP = 300,
     ENDLOOP = 301,
     CONTINUE = 302,
     READ = 303,
     WRITE = 304,
     RETURN = 305
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 10 "mini_l.y"

	int	int_val;
	char *	str_val;


/* Line 387 of yacc.c  */
#line 176 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 204 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   161

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNRULES -- Number of states.  */
#define YYNSTATES  143

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     7,    23,    24,    32,    33,    37,
      38,    44,    45,    48,    57,    65,    74,    78,    80,    83,
      84,    88,    91,    94,    95,    99,   100,   104,   107,   109,
     113,   115,   117,   121,   124,   126,   128,   130,   132,   134,
     136,   137,   141,   145,   148,   149,   153,   157,   161,   164,
     166,   170,   176,   177,   179,   180,   184,   185,   190,   193,
     194,   198,   199
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      52,     0,    -1,    -1,    53,    52,    -1,    27,     4,    10,
      28,    54,    10,    29,    30,    54,    10,    31,    32,    57,
      10,    33,    -1,    -1,     4,    55,    11,    56,    34,    10,
      54,    -1,    -1,    12,     4,    55,    -1,    -1,    35,     7,
       3,     8,    36,    -1,    -1,    74,    26,    -1,    37,    59,
      38,    57,    10,    58,    73,    39,    -1,    43,    59,    45,
      57,    10,    58,    46,    -1,    44,    45,    57,    10,    58,
      46,    43,    59,    -1,    48,    74,    76,    -1,    47,    -1,
      50,    65,    -1,    -1,    57,    10,    58,    -1,    60,    61,
      -1,    63,    62,    -1,    -1,    25,    60,    61,    -1,    -1,
      24,    63,    62,    -1,    23,    64,    -1,    64,    -1,    65,
      66,    65,    -1,    41,    -1,    42,    -1,     5,    59,     6,
      -1,    68,    67,    -1,    21,    -1,    22,    -1,    17,    -1,
      19,    -1,    18,    -1,    20,    -1,    -1,    16,    68,    67,
      -1,     9,    68,    67,    -1,    70,    69,    -1,    -1,    13,
      70,    69,    -1,    14,    70,    69,    -1,    15,    70,    69,
      -1,     9,    74,    -1,     3,    -1,     5,    65,     6,    -1,
       4,     5,    71,    72,     6,    -1,    -1,    65,    -1,    -1,
      12,    65,    72,    -1,    -1,    40,    57,    10,    58,    -1,
       4,    75,    -1,    -1,     7,    65,     8,    -1,    -1,    12,
      74,    76,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    29,    29,    30,    32,    34,    35,    37,    38,    40,
      41,    45,    46,    47,    48,    49,    50,    51,    52,    54,
      55,    59,    61,    63,    64,    66,    67,    70,    71,    73,
      74,    75,    76,    78,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    90,    92,    93,    94,    95,    99,   100,
     101,   102,   104,   105,   107,   108,   112,   113,   117,   119,
     120,   122,   123
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "ID", "L_PARENT", "R_PARENT",
  "L_BRAC", "R_BRAC", "SUB", "SEMICOLON", "COLON", "COMMA", "TIMES", "DIV",
  "MOD", "ADD", "LT", "LTE", "GT", "GTE", "EQ", "NEQ", "NOT", "AND", "OR",
  "ASSIGN", "FUNCTION", "BEGIN_PARAMS", "END_PARAMS", "BEGIN_LOCALS",
  "END_LOCALS", "BEGIN_BODY", "END_BODY", "INTERGER", "ARRAY", "OF", "IF",
  "THEN", "ENDIF", "ELSE", "TRUE", "FALSE", "WHILE", "DO", "BEGINLOOP",
  "ENDLOOP", "CONTINUE", "READ", "WRITE", "RETURN", "$accept", "program",
  "function", "declaration", "comma", "array", "statement",
  "more_statement", "bool_expr", "relation_and_expr", "more_bool_expr",
  "more_relation_and_expr", "relation_expr", "more_relation_expr",
  "expression", "compare", "more_expression", "multiplicative_expr",
  "more_multiplicative_expr", "term", "term_expr", "term_comma", "else",
  "var", "more_var", "var_comma", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    52,    53,    54,    54,    55,    55,    56,
      56,    57,    57,    57,    57,    57,    57,    57,    57,    58,
      58,    59,    60,    61,    61,    62,    62,    63,    63,    64,
      64,    64,    64,    65,    66,    66,    66,    66,    66,    66,
      67,    67,    67,    68,    69,    69,    69,    69,    70,    70,
      70,    70,    71,    71,    72,    72,    73,    73,    74,    75,
      75,    76,    76
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,    15,     0,     7,     0,     3,     0,
       5,     0,     2,     8,     7,     8,     3,     1,     2,     0,
       3,     2,     2,     0,     3,     0,     3,     2,     1,     3,
       1,     1,     3,     2,     1,     1,     1,     1,     1,     1,
       0,     3,     3,     2,     0,     3,     3,     3,     2,     1,
       3,     5,     0,     1,     0,     3,     0,     4,     2,     0,
       3,     0,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     2,     0,     1,     3,     0,     5,     7,
       0,     0,     0,     0,     7,     9,     0,     8,     0,     0,
       5,     0,     0,     0,     0,     5,     0,     0,     6,     0,
      10,    11,    59,     0,     0,     0,    17,     0,     0,     0,
       0,     0,    58,    49,     0,     0,     0,     0,    30,    31,
       0,    23,    25,    28,     0,    40,    44,     0,    11,    61,
       0,    18,     0,    12,     0,    52,     0,     0,    48,    27,
      11,     0,    21,     0,    22,    36,    38,    37,    39,    34,
      35,     0,     0,     0,    33,     0,     0,     0,    43,    11,
       0,     0,    16,     0,     4,    60,    53,    54,    32,    50,
       0,    23,    25,    29,    40,    40,    44,    44,    44,     0,
      11,    61,     0,     0,    19,    24,    26,    42,    41,    45,
      46,    47,    11,     0,     0,    62,    54,    51,    56,     0,
      19,     0,    55,    11,     0,    14,    20,     0,     0,    13,
      15,    11,    57
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    10,    12,    19,   123,   124,    50,    51,
      72,    74,    52,    53,    54,    81,    84,    55,    88,    56,
      97,   113,   134,    40,    42,    92
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -96
static const yytype_int16 yypact[] =
{
      -5,    33,    39,    -5,    40,   -96,   -96,    24,    51,    54,
      58,    68,    69,    50,    54,    57,    63,   -96,   104,    78,
      51,   110,   105,   106,   109,    51,    83,    84,   -96,    86,
     -96,    34,   112,    12,    12,    76,   -96,   118,    22,   115,
     100,    22,   -96,   -96,   122,    12,   118,    82,   -96,   -96,
      90,   107,   111,   -96,    88,    -3,    19,    85,    34,   117,
      22,   -96,    98,   -96,   125,    22,   128,    77,   -96,   -96,
      34,    12,   -96,    12,   -96,   -96,   -96,   -96,   -96,   -96,
     -96,    22,    22,    22,   -96,    22,    22,    22,   -96,    34,
     126,   118,   -96,   131,   -96,   -96,   -96,   127,   -96,   -96,
     130,   107,   111,   -96,    -3,    -3,    19,    19,    19,   132,
      -1,   117,    22,   135,    14,   -96,   -96,   -96,   -96,   -96,
     -96,   -96,    -1,   133,    92,   -96,   127,   -96,   108,    99,
      14,   101,   -96,    34,   113,   -96,   -96,    12,   136,   -96,
     -96,    26,   -96
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -96,   144,   -96,   -13,   137,   -96,   -29,   -74,   -34,    79,
      48,    52,    80,   114,   -37,   -96,   -95,   -63,   -18,    15,
     -96,    29,   -96,   -32,   -96,    45
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -20
static const yytype_int16 yytable[] =
{
      57,    61,    39,    32,    64,    59,    82,    23,    67,   117,
     118,    66,    28,    83,    68,    43,    44,    45,    32,   104,
     105,    46,     1,    93,   -11,    43,    44,    60,    96,    90,
      32,    46,    85,    86,    87,    47,    33,     4,    32,     5,
     128,   100,    34,    35,   103,   -19,    36,    37,   129,    38,
       7,    33,     8,    48,    49,     9,   136,    34,    35,   111,
     109,    36,    37,    33,    38,   -19,    11,   142,    13,    34,
      35,    33,    14,    36,    37,   126,    38,    34,    35,    16,
      15,    36,    37,    99,    38,    43,    44,    45,   119,   120,
     121,    46,    18,    20,    75,    76,    77,    78,    79,    80,
     106,   107,   108,   140,   138,    75,    76,    77,    78,    79,
      80,    21,    22,    24,    29,    25,    26,    27,    31,    41,
      30,    58,    32,    48,    49,    62,    63,    65,    70,    91,
      89,    94,    71,    95,    98,    73,   110,    99,   131,   112,
     114,   127,   122,   130,   137,   135,   141,     6,   133,   115,
     101,    17,   139,   102,   116,   132,   125,     0,     0,     0,
       0,    69
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-96)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      34,    38,    31,     4,    41,    37,     9,    20,    45,   104,
     105,    45,    25,    16,    46,     3,     4,     5,     4,    82,
      83,     9,    27,    60,    10,     3,     4,     5,    65,    58,
       4,     9,    13,    14,    15,    23,    37,     4,     4,     0,
     114,    70,    43,    44,    81,    46,    47,    48,   122,    50,
      10,    37,    28,    41,    42,     4,   130,    43,    44,    91,
      89,    47,    48,    37,    50,    39,    12,   141,    10,    43,
      44,    37,     4,    47,    48,   112,    50,    43,    44,    29,
      11,    47,    48,     6,    50,     3,     4,     5,   106,   107,
     108,     9,    35,    30,    17,    18,    19,    20,    21,    22,
      85,    86,    87,   137,   133,    17,    18,    19,    20,    21,
      22,     7,    34,     3,    31,    10,    10,     8,    32,     7,
      36,    45,     4,    41,    42,    10,    26,     5,    38,    12,
      45,    33,    25,     8,     6,    24,    10,     6,    46,    12,
      10,     6,    10,    10,    43,    46,    10,     3,    40,   101,
      71,    14,    39,    73,   102,   126,   111,    -1,    -1,    -1,
      -1,    47
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    27,    52,    53,     4,     0,    52,    10,    28,     4,
      54,    12,    55,    10,     4,    11,    29,    55,    35,    56,
      30,     7,    34,    54,     3,    10,    10,     8,    54,    31,
      36,    32,     4,    37,    43,    44,    47,    48,    50,    57,
      74,     7,    75,     3,     4,     5,     9,    23,    41,    42,
      59,    60,    63,    64,    65,    68,    70,    59,    45,    74,
       5,    65,    10,    26,    65,     5,    59,    65,    74,    64,
      38,    25,    61,    24,    62,    17,    18,    19,    20,    21,
      22,    66,     9,    16,    67,    13,    14,    15,    69,    45,
      57,    12,    76,    65,    33,     8,    65,    71,     6,     6,
      57,    60,    63,    65,    68,    68,    70,    70,    70,    57,
      10,    74,    12,    72,    10,    61,    62,    67,    67,    69,
      69,    69,    10,    57,    58,    76,    65,     6,    58,    58,
      10,    46,    72,    40,    73,    46,    58,    43,    57,    39,
      59,    10,    58
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 4:
/* Line 1792 of yacc.c  */
#line 32 "mini_l.y"
    {printf("FUNCTION ID SEMICOLON BEGIN_PARAMS declaration SEMICOLON END_PARAMS BEGIN_LOCALS declaration SEMICOLON END_LOCALS BEGIN_BODY statement SEMICOLON END_BODY\n");}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 34 "mini_l.y"
    {printf("Empty declaration.\n");}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 35 "mini_l.y"
    {printf("ID comma COLON array INTEGER SEMICOLON declaration\n");}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 37 "mini_l.y"
    {printf("Empty comma\n");}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 38 "mini_l.y"
    {printf("COMMA ID comma\n");}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 40 "mini_l.y"
    {printf("No array\n");}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 41 "mini_l.y"
    {printf("ARRAY L_BRAC NUMBER R_BRAC OF\n");}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 45 "mini_l.y"
    {printf("Empty statement\n");}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 46 "mini_l.y"
    {printf("var ASSIGN\n");}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 47 "mini_l.y"
    {printf("IF bool_expr THEN statement SEMICOLON more_statement else ENDIF\n");}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 48 "mini_l.y"
    {printf("WHILE bool_expr BEGINLOOP statement SEMICOLON more_statement ENDLOOP\n");}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 49 "mini_l.y"
    {printf("DO BEGINLOOP statement SEMICOLON more_statement ENDLOOP WHILE bool_expr\n");}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 50 "mini_l.y"
    {printf("READ var var_comma\n");}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 51 "mini_l.y"
    {printf("CONTINUE\n");}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 52 "mini_l.y"
    {printf("RETURN expression\n");}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 54 "mini_l.y"
    {printf("Empty statement\n");}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 55 "mini_l.y"
    {printf("statement SEMICOLON more_statement\n");}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 59 "mini_l.y"
    {printf("relation_and_expr more_bool_expr\n");}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 61 "mini_l.y"
    {printf("relation_expr more_relation_and_expr\n");}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 63 "mini_l.y"
    {printf("Empty bool expression\n");}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 64 "mini_l.y"
    {printf("OR relation_and_expr bool_expr\n");}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 66 "mini_l.y"
    {printf("Empty relation_and_expr\n");}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 67 "mini_l.y"
    {printf("AND relation_expr  more_relation_and_expr\n");}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 70 "mini_l.y"
    {printf("NOT more_relation_expr\n");}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 71 "mini_l.y"
    {printf("more_relation_expr\n");}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 73 "mini_l.y"
    {printf("expression compare expression\n");}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 74 "mini_l.y"
    {printf("TRUE\n");}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 75 "mini_l.y"
    {printf("FALSE\n");}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 76 "mini_l.y"
    {printf("L_PARENT bool_expr R_PARENT\n");}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 78 "mini_l.y"
    {printf("multiplicative_expr more_expression\n");}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 80 "mini_l.y"
    {printf("EQ\n");}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 81 "mini_l.y"
    {printf("NEQ\n");}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 82 "mini_l.y"
    {printf("LT\n");}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 83 "mini_l.y"
    {printf("GT\n");}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 84 "mini_l.y"
    {printf("LTE\n");}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 85 "mini_l.y"
    {printf("GTE\n");}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 86 "mini_l.y"
    {printf("Empty expression\n");}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 87 "mini_l.y"
    {printf("ADD multiplicative_expr more_expression\n");}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 88 "mini_l.y"
    {printf("SUB multiplicative_expr more_expression\n");}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 90 "mini_l.y"
    {printf("term more_multiplicative_expr\n");}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 92 "mini_l.y"
    {printf("Empty multiplicative_expr\n");}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 93 "mini_l.y"
    {printf("TIMES term more_multiplicative_expr\n");}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 94 "mini_l.y"
    {printf("DIV term more_multiplicative_expr\n");}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 95 "mini_l.y"
    {printf("MOD term more_multiplicative_expr\n");}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 99 "mini_l.y"
    {printf("SUB var\n");}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 100 "mini_l.y"
    {printf("NUMBER\n");}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 101 "mini_l.y"
    {printf("L_PARENT expression R_PARENT\n");}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 102 "mini_l.y"
    {printf("ID L_PARENT term_expr term_comma R_PARENT\n");}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 104 "mini_l.y"
    {printf("Empty term_expr\n");}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 105 "mini_l.y"
    {printf("expression\n");}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 107 "mini_l.y"
    {printf("Empty term_comma\n");}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 108 "mini_l.y"
    {printf("COMMA expression term_comma\n");}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 112 "mini_l.y"
    {printf("Empty else\n");}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 113 "mini_l.y"
    {printf("ELSE statement SEMICOLON more_statement\n");}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 117 "mini_l.y"
    {printf("ID more_var\n");}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 119 "mini_l.y"
    {printf("Empty var\n");}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 120 "mini_l.y"
    {printf("L_BRAC expression R_BRAC\n");}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 122 "mini_l.y"
    {printf("Empty var_comma\n");}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 123 "mini_l.y"
    {printf("COMMA var var_comma\n");}
    break;


/* Line 1792 of yacc.c  */
#line 1876 "y.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 128 "mini_l.y"

void yyerr(int error_code, char* error_symbol) {
	switch (error_code)  {
		case 1: {
			printf("Error at line %d, column %d: unrecognized symbol \"%s\"\n", lineNum, colNum, error_symbol);
		break;
		}
		case 2: {
			printf("Error at line %d, column %d: identifier \"%s\" must begin with a letter\n", lineNum, colNum, error_symbol);
		break;
		}
		case 3: {
			printf("Error at line %d, column %d: identifier \"%s\" cannot end with an underscore\n", lineNum, colNum, error_symbol);
		break;
		}
	}
	exit(1);
}


int main(int argc, char** argv){
    FILE *fh;

    if(argc == 2 && (fh = fopen(argv[1], "r")))
        yyin = fh;
    else
	yyin = stdin;
    yylex();

}
