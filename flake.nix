{
  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };
  description = "dmenu";
  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        systems = lib.systems.flakeExposed;
        lib = nixpkgs.lib;
        eachSystem = lib.genAttrs systems;
        pkgs = self.legacyPackages.${system};
      in {
        legacyPackages = import nixpkgs { inherit system; };
        packages.dmenu = let pkgs = self.legacyPackages.${system};
        in pkgs.stdenv.mkDerivation rec {
          version = "0.5.2";
          name = "dmenu-${version}";
          src = lib.cleanSource ./.;

          nativeBuildInputs = with pkgs; [ pkg-config ];
          buildInputs = with pkgs; [
            fribidi
            xorg.libX11
            xorg.libXext
            xorg.libXinerama
            xorg.libXft
          ];

          postPatch = ''
            sed -ri -e 's!\<(dmenu|dmenu_path|stest)\>!'"$out/bin"'/&!g' dmenu_run
            sed -ri -e 's!\<stest\>!'"$out/bin"'/&!g' dmenu_path
          '';

          preConfigure = ''
            sed -i "s@PREFIX = /usr/local@PREFIX = $out@g" config.mk
          '';

          makeFlags = [ "CC:=$(CC)" ];
          enableParallelBuilding = true;
          doCheck = true;
          meta = with lib; {
            description =
              "A generic, highly customizable, and efficient menu for the X Window System";
            homepage = "https://github.com/andreoss/dmenu";
            license = licenses.gpl3;
            maintainers = [ ];
            platforms = platforms.all;
          };
        };
        packages.dwm = let pkgs = self.legacyPackages.${system};
        in pkgs.writeShellApplication {
          name = "dwm";
          checkPhase = ":";
          runtimeInputs = [ self.packages.${system}.dmenu ];
          text = "exec ${self.packages.${system}.dmenu}/bin/dwm $@";
        };
        packages.passmenu = let pkgs = self.legacyPackages.${system};
        in pkgs.writeShellApplication {
          name = "passmenu";
          checkPhase = ":";
          runtimeInputs = [ self.packages.${system}.dmenu ];
          text = "${./passmenu}";
        };
        packages.dmenu_run = let pkgs = self.legacyPackages.${system};
        in pkgs.writeShellApplication {
          name = "dmenu_run";
          checkPhase = ":";
          runtimeInputs = [ self.packages.${system}.dmenu ];
          text = builtins.readFile (pkgs.substituteAll { src = ./dmenu_run; });
        };
        packages.default = self.packages.${system}.dmenu;
        devShells.default = pkgs.mkShell {
          buildInputs = self.packages.${system}.default.buildInputs;
          shellHook = ''
            echo xxx
          '';

        };
      });
}
