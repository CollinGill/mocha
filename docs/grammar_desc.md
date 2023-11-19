# Mocha Grammar

## Grammar Derivations

$$
\begin{align*}

\langle \text{program} \rangle \to\:&
    \langle\text{stmt-list}\rangle\\

\langle\text{stmt-list}\rangle \to\:&
    \langle\text{stmt}\rangle
    \langle\text{stmt-list}\rangle\\
|\:& \langle\text{stmt}\rangle\\

\langle\text{stmt}\rangle \to\:&
    \langle\text{decl}\rangle\\
|\:& \langle\text{assign}\rangle\\
|\:& \langle\text{func-decl}\rangle\\
|\:& \langle\text{expr}\rangle
    \langle\text{SEMI}\rangle\\

\langle\text{decl}\rangle \to\:&
    \langle\text{mut}\rangle
    \langle\text{IDENTIFIER}\rangle
    \langle\text{COLON}\rangle
    \langle\text{TYPE}\rangle
    \langle\text{decl-end}\rangle\\

\langle\text{mut}\rangle \to\:&
    \langle\text{VAR}\rangle\\
|\:& \langle\text{CONST}\rangle\\

\langle\text{decl-end}\rangle \to\:&
    \langle\text{EQU}\rangle
    \langle\text{expr}\rangle
    \langle\text{SEMI}\rangle\\
|\:& \langle\text{SEMI}\rangle\\

\langle\text{assign}\rangle \to\:&
    \langle\text{IDENTIFIER}\rangle
    \langle\text{EQU}\rangle
    \langle\text{expr}\rangle
    \langle\text{SEMI}\rangle\\

\langle\text{func-decl}\rangle \to\:&
    \langle\text{FUNC}\rangle
    \langle\text{IDENTIFIER}\rangle
    \langle\text{L-PAREN}\rangle
    \langle\text{arg-list}\rangle
    \langle\text{R-PAREN}\rangle
    \langle\text{ARROW}\rangle
    \langle\text{TYPE}\rangle
    \langle\text{L-BRACKET}\rangle
    \langle\text{func-body}\rangle
    \langle\text{R-BRACKET}\rangle\\

\langle\text{param-list}\rangle \to\:&
    \langle\text{param}\rangle
    \langle\text{param-list'}\rangle\\
|\:& \langle\text{EPS}\rangle\\

\langle\text{param-list'}\rangle \to\:&
    \langle\text{COMMA}\rangle
    \langle\text{param}\rangle
    \langle\text{param-list'}\rangle\\
|\:& \langle\text{EPS}\rangle\\

\langle\text{param}\rangle \to\:&
    \langle\text{IDENTIFIER}\rangle\\

\langle\text{func-body}\rangle \to\:&
    \langle\text{body-stmt-list}\rangle
    \langle\text{RETURN}\rangle
    \langle\text{expr}\rangle
    \langle\text{SEMI}\\

\langle\text{body-stmt-list}\rangle \to\:&
    \langle\text{body-stmt}\rangle
    \langle\text{body-stmt-list}\rangle\\
|\:& \langle\text{EPS}\rangle\\

\langle\text{body-stmt}\rangle \to\:&
    \langle\text{decl}\rangle\\
|\:& \langle\text{assign}\rangle\\
|\:& \langle\text{expr}\rangle\\

\langle\text{expr}\rangle \to\:&
    \langle\text{arith-expr}\rangle\\
|\:& \langle\text{func-call}\rangle\\
|\:& \langle\text{STRING-LIT}\rangle\\
|\:& \langle\text{CHAR-LIT}\rangle\\

\langle\text{arith-expr}\rangle \to\:&
\\

\langle\text{number}\rangle \to\:&
    \langle\text{INT-LIT}\rangle\\
|\:& \langle\text{FLOAT-LIT}\rangle\\

\langle\text{func-call}\rangle \to\:&
    \langle\text{IDENTIFIER}\rangle
    \langle\text{L-PAREN}\rangle
    \langle\text{arg-list}\rangle
    \langle\text{R-PAREN}\rangle
\\

\langle\text{arg-list}\rangle \to\:&
    \langle\text{arg}\rangle
    \langle\text{arg-list'}\rangle\\
|\:& \langle\text{EPS}\rangle\\

\langle\text{arg-list'}\rangle \to\:&
    \langle\text{COMMA}\rangle
    \langle\text{arg}\rangle
    \langle\text{arg-list'}\rangle\\
|\:& \langle\text{EPS}\rangle\\

\langle\text{arg}\rangle \to\:&
    \langle\text{IDENTIFIER}\rangle
    \langle\text{COLON}\rangle
    \langle\text{TYPE}\rangle\\

\end{align*}
$$

## Non-terminals

$$
\begin{align*}
    &\langle\text{EPS}\rangle\\
    &\langle\text{IDENTIFIER}\rangle\\
    &\langle\text{INT-LIT}\rangle\\
    &\langle\text{FLOAT-LIT}\rangle\\
    &\langle\text{STRING-LIT}\rangle\\
    &\langle\text{CHAR-LIT}\rangle\\
    &\langle\text{SEMI}\rangle\\
    &\langle\text{COLON}\rangle\\
    &\langle\text{COMMA}\rangle\\
    &\langle\text{L-PAREN}\rangle\\
    &\langle\text{R-PAREN}\rangle\\
    &\langle\text{L-BRACKET}\rangle\\
    &\langle\text{R-BRACKET}\rangle\\
    &\langle\text{FUNC}\rangle\\
    &\langle\text{ARROW}\rangle\\
    &\langle\text{RETURN}\rangle\\
    &\langle\text{EQU}\rangle\\
    &\langle\text{TYPE}\rangle\\
    &\langle\text{VAR}\rangle\\
    &\langle\text{CONST}\rangle\\
    &\langle\text{PLUS}\rangle\\
    &\langle\text{MINUS}\rangle\\
    &\langle\text{MULT}\rangle\\
    &\langle\text{DIV}\rangle\\
    &\langle\text{MOD}\rangle\\
    &\langle\text{EXP}\rangle\\

\end{align*}
$$
