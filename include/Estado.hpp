#ifndef ESTADO_HPP
#define ESTADO_HPP

class Estado{
    public:
        virtual ~Estado();
        virtual int executar() = 0;
};

#endif