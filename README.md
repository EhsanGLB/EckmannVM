# EckmannVM
This is a library for Eckmann viscosity model written based on foam-extend-4.1.


## Mathematical Relationships
$$ {\nu} = {e^{ {\lambda \over \dot{\gamma} } + \eta Hct } \over \rho} {\left({\alpha + {\phi \over {1 + e^{\beta \left({T - \xi}\right) } } } }\right)} $$

Which $\nu$, $\dot{\gamma}$, $T$, and $Hct$ are kinematic viscosity, strain rate, temperature, and hematocrit, respectively. Also, The constants $\lambda$, $\eta$, $\alpha$, $\phi$, $\beta$, and $\xi$ describe the individual shear, thermal, and volume fraction effects of a particular diluent.


## Installation
It is working on foam-extend-4.1
```bash
git clone https://github.com/EhsanGLB/EckmannVM.git
cd EckmannVM/EckmannVM
wmake libso
cd ../case
```


## Getting Started
```bash
blockMesh
nonNewtonianIcoFoam
```


## Activation
Add "libEckmannVM.so" to case/system/controlDict


## Origin References
* [Eckmann, D.M., Bowers, S., Stecker, M. and Cheung, A.T., 2000. Hematocrit, volume expander, temperature, and shear rate effects on blood viscosity. Anesthesia & Analgesia, 91(3), pp.539-545.](https://journals.lww.com/anesthesia-analgesia/FullText/2000/09000/Hematocrit,_Volume_Expander,_Temperature,_and.7.aspx)


## References
* [Golab, Ehsan, Behzad Vahedi, Ankur Jain, Robert A. Taylor, and Kambiz Vafai. "Laminar forced convection in a tube with a nano-encapsulated phase change materials: Minimizing exergy losses and maximizing the heat transfer rate." Journal of Energy Storage 65 (2023): 107233.](https://www.sciencedirect.com/science/article/abs/pii/S2352152X23006308)
* [Vahedi, Behzad, Ehsan Golab, Arsalan Nasiri Sadr, and Kambiz Vafai. "Thermal, thermodynamic and exergoeconomic investigation of a parabolic trough collector utilizing nanofluids." Applied Thermal Engineering 206 (2022): 118117.](https://www.sciencedirect.com/science/article/abs/pii/S1359431122000813)
* [Golab, Ehsan, Sahar Goudarzi, Hamed Kazemi-Varnamkhasti, Hossein Amigh, Ferial Ghaemi, Dumitru Baleanu, and Arash Karimipour. "Investigation of the effect of adding nano-encapsulated phase change material to water in natural convection inside a rectangular cavity." Journal of Energy Storage 40 (2021): 102699.](https://www.sciencedirect.com/science/article/abs/pii/S2352152X21004357)
* [Abbasi, Mohammad, Amin Nadimian Esfahani, Ehsan Golab, Omid Golestanian, Nima Ashouri, S. Mohammad Sajadi, Ferial Ghaemi, Dumitru Baleanu, and A. Karimipour. "Effects of Brownian motions and thermophoresis diffusions on the hematocrit and LDL concentration/diameter of pulsatile non-Newtonian blood in abdominal aortic aneurysm." Journal of Non-Newtonian Fluid Mechanics 294 (2021): 104576.](https://www.sciencedirect.com/science/article/abs/pii/S0377025721000859)
* [Jafarzadeh, Sina, Arsalan Nasiri Sadr, Ehsan Kaffash, Sahar Goudarzi, Ehsan Golab, and Arash Karimipour. "The effect of hematocrit and nanoparticles diameter on hemodynamic parameters and drug delivery in abdominal aortic aneurysm with consideration of blood pulsatile flow." Computer Methods and Programs in Biomedicine 195 (2020): 105545.](https://www.sciencedirect.com/science/article/abs/pii/S0169260720307914)
* [Goudarzi, Sahar, Masih Shekaramiz, Alireza Omidvar, Ehsan Golab, Arash Karimipour, and Aliakbar Karimipour. "Nanoparticles migration due to thermophoresis and Brownian motion and its impact on Ag-MgO/Water hybrid nanofluid natural convection." Powder Technology 375 (2020): 493-503.](https://www.sciencedirect.com/science/article/abs/pii/S0032591020307397)
* [Motlagh, Saber Yekani, Ehsan Golab, and Arsalan Nasiri Sadr. "Two-phase modeling of the free convection of nanofluid inside the inclined porous semi-annulus enclosure." International Journal of Mechanical Sciences 164 (2019): 105183.](https://www.sciencedirect.com/science/article/abs/pii/S0020740319315279)
