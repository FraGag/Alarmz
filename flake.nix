{
  description = "Shows alarms/reminders at configured schedules";

  inputs = {
    flake-utils.url = "github:numtide/flake-utils";
    nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";
  };

  outputs = { self, flake-utils, nixpkgs }:

    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = import nixpkgs { inherit system; };
        Alarmz =
          { mkDerivation
          , lib
          , qmake
          , qtbase
          , qtmultimedia
          , python3
          }:
          let
            pythonEnv = python3.withPackages (ps: with ps; [ lxml ]);
          in
          mkDerivation rec {
            pname = "Alarmz";
            version = "2.0.3";

            src = ./.;

            nativeBuildInputs = [ qmake ];

            buildInputs = [ qtbase qtmultimedia ];

            qmakeFlags = [ "target.path=${placeholder "out"}/lib/Alarmz" "INSTALLS+=target" ];

            postBuild = ''
              cd doc/
              ${pythonEnv}/bin/python3 generate-html.py
              cd ../
            '';

            postInstall = ''
              mkdir -p $out/bin $out/lib/Alarmz/doc/en_US $out/lib/Alarmz/doc/fr
              cp Alarmz_fr.qm $out/lib/Alarmz/
              cp doc/style.css $out/lib/Alarmz/doc/
              cp doc/en_US/*.html $out/lib/Alarmz/doc/en_US/
              cp doc/fr/*.html $out/lib/Alarmz/doc/fr/
              ln -s $out/lib/Alarmz/Alarmz $out/bin/Alarmz
            '';

            meta = with lib; {
              homepage = "https://github.com/FraGag/Alarmz";
              description = "Alarmz";
              license = licenses.gpl3Plus;
            };
          };
      in
      {
        packages.default = pkgs.qt5.callPackage Alarmz {};
      }
    );

}
