# Usamos una imagen base oficial y ligera de Alpine Linux
FROM alpine:latest

# Instalamos el paquete curl dentro del contenedor
RUN apk update && apk add curl

# Comando que se ejecutará por defecto cuando el contenedor arrancar
CMD ["echo", "¡Hola, yo soy tu contenedor de Docker!"]