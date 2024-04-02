CFILES = $(wildcard *.c)
OFILES = $(CFILES:.c=.o)

GCCFLAGS = -Wall -O2 -ffreestanding -nostdinc -nostdlib -nostartfiles
GCCPATH = /opt/arm-toolchain-aarch64-elf/bin

all: clean kernel8.img

boot.o: boot.asm
	$(GCCPATH)/aarch64-none-elf-gcc $(GCCFLAGS) -x assembler -c boot.asm -o boot.o

%.o: %.c
	$(GCCPATH)/aarch64-none-elf-gcc $(GCCFLAGS) -c $< -o $@

kernel8.img: boot.o $(OFILES)
	$(GCCPATH)/aarch64-none-elf-ld -nostdlib boot.o $(OFILES) -T link.ld -o kernel8.elf
	$(GCCPATH)/aarch64-none-elf-objcopy -O binary kernel8.elf kernel8.img

clean:
	rm kernel8.elf *.o *.img > /dev/null 2> /dev/null || true
	