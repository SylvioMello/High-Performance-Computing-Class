program main
    !Alocação dos espaços que ficarão os vetores e a matriz
    !Declaração das variáveis necessárias para o programa
    real, allocatable :: x(:)
    real, allocatable :: b(:)
    real, allocatable :: matrix(:, :)
    character(100) :: nchar
    integer :: n
    integer :: i
    real :: start, finish

    if (command_argument_count().ne.1) then
        stop "pare"
    endif

    call get_command_argument(1, nchar)   

    read (nchar,*)n
    
    !Começo da contagem do tempo
    call cpu_time(start)
    
    !Efetivamente alocando valores dentro do vetor e da matriz
    allocate(x(n))
    allocate(b(n))
    allocate(matrix(n, n))

    call random_number(matrix)
    call random_number(x)

    !Produto Matriz Vetor
    do i = 1, n
        do j = 1, n
            b(i) = b(i) + matrix(i, j) * x(j)
        end do
    end do

    !Desalocando os vetores e a matriz após o produto
    deallocate(x)
    deallocate(b)
    deallocate(matrix)

    !Encerrando a contagem do tempo para métricas
    call cpu_time(finish)
    print *, finish - start

    !Alocação dos pontos em um arquivo excel
    open(unit=40, file='pontos_em_Fortran.csv', action='write', position='append')
    write(40,'(g0.7","g0.7)') n, finish-start
    
    close(40)

end program main
